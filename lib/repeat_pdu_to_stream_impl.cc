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

#pragma message("set the following appropriately and remove this warning")
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
      d_num_reps(num_repetitions)
{
    this->message_port_register_in(pmt::mp("in"));
    this->set_msg_handler(pmt::mp("in"),
                          [this](const pmt::pmt_t& pdu) { handle_msg(pdu); });
}

void repeat_pdu_to_stream_impl::handle_msg(const pmt::pmt_t &pdu) {
  // TODO: Implement me

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

#pragma message("Implement the signal processing in your block and remove this warning")
    // Do <+signal processing+>

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace plasma */
} /* namespace gr */
