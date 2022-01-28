/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "repeat_pdu_to_stream_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace plasma {

using output_type = gr_complex;
repeat_pdu_to_stream::sptr repeat_pdu_to_stream::make(size_t num_repetitions)
{
    return gnuradio::make_block_sptr<repeat_pdu_to_stream_impl>(num_repetitions);
}


/*
 * The private constructor
 */
repeat_pdu_to_stream_impl::repeat_pdu_to_stream_impl(size_t num_repetitions)
    : gr::sync_block("repeat_pdu_to_stream",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
      d_num_reps(num_repetitions),
      d_curr_index(0)
{
    this->message_port_register_in(pmt::mp("in"));
    this->set_msg_handler(pmt::mp("in"),
                          [this](const pmt::pmt_t& pdu) { store_pdu(pdu); });
}

void repeat_pdu_to_stream_impl::store_pdu(const pmt::pmt_t& pdu)
{
    // make sure PDU data is formed properly
    if (!(pmt::is_pdu(pdu))) {
        GR_LOG_ERROR(this->d_logger, "PMT is not a PDU, dropping");
        return;
    }


    // Parse the PDU
    pmt::pmt_t meta = pmt::car(pdu);
    pmt::pmt_t v_data = pmt::cdr(pdu);

    size_t num_bytes = 0;
    size_t num_items = 0;
    const gr_complex* d_in =
        static_cast<const gr_complex*>(pmt::uniform_vector_elements(v_data, num_bytes));
    num_items = num_bytes / sizeof(gr_complex);
    d_data = std::vector<gr_complex>(d_in, d_in + num_items);
}

/*
 * Our virtual destructor.
 */
repeat_pdu_to_stream_impl::~repeat_pdu_to_stream_impl() {}

int repeat_pdu_to_stream_impl::work(int noutput_items,
                                    gr_vector_const_void_star& input_items,
                                    gr_vector_void_star& output_items)
{
    auto out = static_cast<output_type*>(output_items[0]);

    size_t data_remaining = d_data.size() - d_curr_index;
    size_t produced;
    if (data_remaining == 0) {
        // if we have nothing to do, sleep for a short duration to prevent rapid
        // successive calls and then return zero items
        boost::this_thread::sleep(boost::posix_time::microseconds(25));
        return 0;
    }

    if (data_remaining <= static_cast<size_t>(noutput_items)) {
        memcpy(out, &d_data[d_curr_index], data_remaining * sizeof(output_type));
        d_curr_index = 0;
        produced = data_remaining;
    } else {
        // Not everything will fit in the current buffer, copy as much as we can
        // to the output
        if (noutput_items) {
            memcpy(out, &d_data[d_curr_index], noutput_items * sizeof(output_type));
            d_curr_index += noutput_items;
            produced = noutput_items;
        }
    }

    // Tell runtime system how many output items we produced.
    return produced;
}

} /* namespace plasma */
} /* namespace gr */
