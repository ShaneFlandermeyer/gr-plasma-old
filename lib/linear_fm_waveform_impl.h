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
      std::atomic<bool> d_finished;
      gr::thread::thread d_thread;

      void send();

     public:
      linear_fm_waveform_impl(double bandwidth, double pulsewidth, double prf, double samp_rate);
      ~linear_fm_waveform_impl();
      bool start() override;
      bool stop() override;
      

    };

  } // namespace plasma
} // namespace gr

#endif /* INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_IMPL_H */
