/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_IMPL_H
#define INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_IMPL_H

#include <gnuradio/plasma/linear_fm_waveform.h>
#include <plasma-dsp/linear-fm-waveform.h>

namespace gr {
namespace plasma {

class linear_fm_waveform_impl : public linear_fm_waveform
{
private:
    // Waveform parameters
    // TODO: Can't make this a member until I fix the waveform's default ctr.
    // ::plasma::LinearFMWaveform d_waveform;
    double d_bandwidth;
    double d_pulsewidth;
    double d_prf;
    double d_samp_rate;
    // Transmitted data vector
    pmt::pmt_t d_data;
    // Thread members for start() and stop()
    std::atomic<bool> d_finished;
    gr::thread::thread d_thread;

    void send();

public:
    linear_fm_waveform_impl(double bandwidth,
                            double pulsewidth,
                            double prf,
                            double samp_rate);
    ~linear_fm_waveform_impl();
    bool start() override;
    bool stop() override;
};

} // namespace plasma
} // namespace gr

#endif /* INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_IMPL_H */
