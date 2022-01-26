/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "pdu_to_stream_repeat_impl.h"

namespace gr {
  namespace plasma {

    #pragma message("set the following appropriately and remove this warning")
    using input_type = float;
    #pragma message("set the following appropriately and remove this warning")
    using output_type = float;
    pdu_to_stream_repeat::sptr
    pdu_to_stream_repeat::make()
    {
      return gnuradio::make_block_sptr<pdu_to_stream_repeat_impl>(
        );
    }


    /*
     * The private constructor
     */
    pdu_to_stream_repeat_impl::pdu_to_stream_repeat_impl()
      : gr::sync_block("pdu_to_stream_repeat",
              gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
              gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
    {}

    /*
     * Our virtual destructor.
     */
    pdu_to_stream_repeat_impl::~pdu_to_stream_repeat_impl()
    {
    }

    int
    pdu_to_stream_repeat_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      auto in = static_cast<const input_type*>(input_items[0]);
      auto out = static_cast<output_type*>(output_items[0]);

      #pragma message("Implement the signal processing in your block and remove this warning")
      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace plasma */
} /* namespace gr */
