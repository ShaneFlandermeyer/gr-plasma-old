/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "pdu_to_stream_repeat_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace plasma {

pdu_to_stream_repeat::sptr pdu_to_stream_repeat::make()
{
    return gnuradio::make_block_sptr<pdu_to_stream_repeat_impl>();
}


/*
 * The private constructor
 */
pdu_to_stream_repeat_impl::pdu_to_stream_repeat_impl()
    : gr::sync_block("pdu_to_stream_repeat",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(gr_complex)))
{
    this->message_port_register_in(pmt::mp("pdu"));
}

/*
 * Our virtual destructor.
 */
pdu_to_stream_repeat_impl::~pdu_to_stream_repeat_impl() {}

int pdu_to_stream_repeat_impl::work(int noutput_items,
                                    gr_vector_const_void_star& input_items,
                                    gr_vector_void_star& output_items)
{
    // auto in = static_cast<const input_type*>(input_items[0]);
    auto out = static_cast<gr_complex*>(output_items[0]);

#pragma message("Implement the signal processing in your block and remove this warning")
    // Do <+signal processing+>

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace plasma */
} /* namespace gr */
