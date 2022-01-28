/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PLASMA_REPEAT_PDU_TO_STREAM_IMPL_H
#define INCLUDED_PLASMA_REPEAT_PDU_TO_STREAM_IMPL_H

#include <gnuradio/plasma/repeat_pdu_to_stream.h>

namespace gr {
  namespace plasma {

    class repeat_pdu_to_stream_impl : public repeat_pdu_to_stream
    {
     private:
      // Nothing to declare in this block.

     public:
      repeat_pdu_to_stream_impl(size_t num_repetitions);
      ~repeat_pdu_to_stream_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace plasma
} // namespace gr

#endif /* INCLUDED_PLASMA_REPEAT_PDU_TO_STREAM_IMPL_H */
