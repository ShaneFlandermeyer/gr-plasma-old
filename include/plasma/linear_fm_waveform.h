/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_H
#define INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_H

#include <gnuradio/sync_block.h>
#include <plasma-dsp/linear-fm-waveform.h>
#include <plasma/api.h>

namespace gr {
namespace plasma {

using LinearFMWaveform = ::plasma::LinearFMWaveform;

/*!
 * \brief <+description of block+>
 * \ingroup plasma
 *
 */
class PLASMA_API linear_fm_waveform : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<linear_fm_waveform> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of plasma::linear_fm_waveform.
     *
     * To avoid accidental use of raw pointers, plasma::linear_fm_waveform's
     * constructor is in a private implementation
     * class. plasma::linear_fm_waveform::make is the public interface for
     * creating new instances.
     */
    static sptr make(double bandwidth, double pulsewidth, double prf, double samp_rate);
};

} // namespace plasma
} // namespace gr

#endif /* INCLUDED_PLASMA_LINEAR_FM_WAVEFORM_H */
