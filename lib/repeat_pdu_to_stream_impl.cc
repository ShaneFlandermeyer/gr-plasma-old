/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "repeat_pdu_to_stream_impl.h"

namespace gr {
  namespace plasma {

    #pragma message("set the following appropriately and remove this warning")
    using input_type = float;
    repeat_pdu_to_stream::sptr
    repeat_pdu_to_stream::make(size_t num_repetitions)
    {
      return gnuradio::make_block_sptr<repeat_pdu_to_stream_impl>(
        num_repetitions);
    }


    /*
     * The private constructor
     */
    repeat_pdu_to_stream_impl::repeat_pdu_to_stream_impl(size_t num_repetitions)
      : gr::sync_block("repeat_pdu_to_stream",
              gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
              gr::io_signature::make(0, 0, 0))
    {}

    /*
     * Our virtual destructor.
     */
    repeat_pdu_to_stream_impl::~repeat_pdu_to_stream_impl()
    {
    }

    int
    repeat_pdu_to_stream_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      auto in = static_cast<const input_type*>(input_items[0]);

      #pragma message("Implement the signal processing in your block and remove this warning")
      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace plasma */
} /* namespace gr */
