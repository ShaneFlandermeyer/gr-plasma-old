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

// TODO: Resolve this namespace problem
using LinearFMWaveform = plasma::LinearFMWaveform;
namespace gr {
namespace plasma {

class linear_fm_waveform_impl : public linear_fm_waveform
{
private:
    // Nothing to declare in this block.
    double d_bandwidth;
    double d_pulsewidth;
    double d_prf;
    double d_samp_rate;
    size_t d_curr_index;
    // TODO: For some reason, gnuradio dies when I make this a class member
    // LinearFMWaveform d_waveform;
    Eigen::ArrayXcf d_data;
public:
    linear_fm_waveform_impl(double bandwidth,
                            double pulsewidth,
                            double prf,
                            double samp_rate);
    ~linear_fm_waveform_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace plasma
} // namespace gr

#endif /* INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_IMPL_H */
