/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "linear_fm_waveform_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace plasma {

using output_type = gr_complex;
linear_fm_waveform::sptr linear_fm_waveform::make(double bandwidth,
                                                  double pulsewidth,
                                                  double prf,
                                                  double samp_rate)
{
    return gnuradio::make_block_sptr<linear_fm_waveform_impl>(
        bandwidth, pulsewidth, prf, samp_rate);
}


/*
 * The private constructor
 */
linear_fm_waveform_impl::linear_fm_waveform_impl(double bandwidth,
                                                 double pulsewidth,
                                                 double prf,
                                                 double samp_rate)
    : gr::sync_block("linear_fm_waveform",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
      d_bandwidth(bandwidth),
      d_pulsewidth(pulsewidth),
      d_prf(prf),
      d_samp_rate(samp_rate),
      d_curr_index(0)
{
    // Create the data vector
    LinearFMWaveform wave(bandwidth, pulsewidth, prf, samp_rate);
    d_data = wave.pulse().cast<output_type>();
}

/*
 * Our virtual destructor.
 */
linear_fm_waveform_impl::~linear_fm_waveform_impl() {}

int linear_fm_waveform_impl::work(int noutput_items,
                                  gr_vector_const_void_star& input_items,
                                  gr_vector_void_star& output_items)
{
    auto out = static_cast<output_type*>(output_items[0]);

    for (size_t i = 0; i < static_cast<size_t>(noutput_items); i++) {
        out[i] = d_data[d_curr_index];
        d_curr_index = (d_curr_index + 1) % d_data.size();
    }

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace plasma */
} /* namespace gr */
