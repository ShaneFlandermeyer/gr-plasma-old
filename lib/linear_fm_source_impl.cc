/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "linear_fm_source_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace plasma {

using output_type = gr_complex;
linear_fm_source::sptr
linear_fm_source::make(double bandwidth, double pulsewidth, double prf, double samp_rate)
{
    return gnuradio::make_block_sptr<linear_fm_source_impl>(
        bandwidth, pulsewidth, prf, samp_rate);
}


/*
 * The private constructor
 */
linear_fm_source_impl::linear_fm_source_impl(double bandwidth,
                                             double pulsewidth,
                                             double prf,
                                             double samp_rate)
    : gr::sync_block("linear_fm_source",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
      d_data_index(0)
{
    d_waveform = ::plasma::LinearFMWaveform(bandwidth, pulsewidth, prf, samp_rate);
    d_data = d_waveform.step().cast<gr_complex>();
}

/*
 * Our virtual destructor.
 */
linear_fm_source_impl::~linear_fm_source_impl() {}

int linear_fm_source_impl::work(int noutput_items,
                                gr_vector_const_void_star& input_items,
                                gr_vector_void_star& output_items)
{
    auto out = static_cast<output_type*>(output_items[0]);
    size_t num_items_to_copy = std::min(noutput_items, (int)d_data.size() - d_data_index);
    memcpy(out, d_data.data() + d_data_index, sizeof(output_type) * num_items_to_copy);
    d_data_index = (d_data_index + num_items_to_copy) % d_data.size();

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace plasma */
} /* namespace gr */
