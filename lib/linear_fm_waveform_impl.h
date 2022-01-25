/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_IMPL_H
#define INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_IMPL_H

#include <gnuradio/plasma/linear_fm_waveform.h>

namespace gr {
  namespace plasma {

    class linear_fm_waveform_impl : public linear_fm_waveform
    {
     private:
      // Nothing to declare in this block.

     public:
      linear_fm_waveform_impl(double bandwidth, double pulsewidth, double prf, double samp_rate);
      ~linear_fm_waveform_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);

    };

  } // namespace plasma
} // namespace gr

#endif /* INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_IMPL_H */
