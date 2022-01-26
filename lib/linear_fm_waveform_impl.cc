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
    : gr::block("linear_fm_waveform",
                gr::io_signature::make(0 /* min inputs */, 0 /* max inputs */, 0),
                gr::io_signature::make(0 /* min outputs */, 0 /*max outputs */, 0)),
      d_bandwidth(bandwidth),
      d_pulsewidth(pulsewidth),
      d_prf(prf),
      d_samp_rate(samp_rate)
{
    ::plasma::LinearFMWaveform waveform(bandwidth, pulsewidth, prf, samp_rate);
    Eigen::ArrayXcf data = waveform.waveform().cast<gr_complex>();
    d_data = pmt::init_c32vector(data.size(), data.data());
    message_port_register_out(pmt::mp("out"));
}


/*
 * Our virtual destructor.
 */
linear_fm_waveform_impl::~linear_fm_waveform_impl() {}

bool linear_fm_waveform_impl::start()
{
    d_finished = false;
    d_thread = gr::thread::thread([this] { send(); });
    return block::start();
}

bool linear_fm_waveform_impl::stop()
{
    d_finished = true;
    d_thread.interrupt();
    d_thread.join();

    return block::stop();
}

void linear_fm_waveform_impl::send()
{
  message_port_pub(pmt::mp("out"), pmt::cons(pmt::PMT_NIL, d_data));
    // // Create the PDU
    // // TODO: Implement time tags
    // // TODO: Add some way to slow down if the PDU->stream queue fills up
    // // I think it may be best to write a special block for this that takes a
    // // single waveform pdu and sends it continuously, rather than sending a new
    // // PDU every PRI. That way, we only have to send a PDU if the waveform
    // // changes. We might still be in trouble if pulse-to-pulse adaptation is
    // // ever required, but it's a start!
    // double whole, frac;
    // pmt::pmt_t meta = pmt::make_dict();
    // pmt::pmt_t time;
    // // Send a message every 100 ms until the program is finished
    // while (!d_finished) {
    //     message_port_pub(pmt::mp("out"), pmt::cons(pmt::PMT_NIL, d_data));
    //     d_time += 1 / d_prf;
    //     boost::this_thread::sleep(
    //         boost::posix_time::seconds(static_cast<long>(1 / d_prf)));
    //     if (d_finished) {
    //         return;
    //     }
    // }
}


} /* namespace plasma */
} /* namespace gr */
