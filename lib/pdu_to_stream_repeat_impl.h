/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PLASMA_PDU_TO_STREAM_REPEAT_IMPL_H
#define INCLUDED_PLASMA_PDU_TO_STREAM_REPEAT_IMPL_H

#include <gnuradio/plasma/pdu_to_stream_repeat.h>

namespace gr {
  namespace plasma {

    class pdu_to_stream_repeat_impl : public pdu_to_stream_repeat
    {
     private:
      // Nothing to declare in this block.

     public:
      pdu_to_stream_repeat_impl();
      ~pdu_to_stream_repeat_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace plasma
} // namespace gr

#endif /* INCLUDED_PLASMA_PDU_TO_STREAM_REPEAT_IMPL_H */
