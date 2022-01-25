/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "linear_fm_waveform_impl.h"

namespace gr {
  namespace plasma {

    #pragma message("set the following appropriately and remove this warning")
    using input_type = gr_complex;
    #pragma message("set the following appropriately and remove this warning")
    using output_type = gr_complex;
    linear_fm_waveform::sptr
    linear_fm_waveform::make(double bandwidth, double pulsewidth, double prf, double samp_rate)
    {
      return gnuradio::make_block_sptr<linear_fm_waveform_impl>(
        bandwidth, pulsewidth, prf, samp_rate);
    }


    /*
     * The private constructor
     */
    linear_fm_waveform_impl::linear_fm_waveform_impl(double bandwidth, double pulsewidth, double prf, double samp_rate)
      : gr::block("linear_fm_waveform",
              gr::io_signature::make(0 /* min inputs */, 0 /* max inputs */, sizeof(input_type)),
              gr::io_signature::make(0 /* min outputs */, 0 /*max outputs */, sizeof(output_type)))
    {
      message_port_register_out(pmt::mp("out"));
    }

    /*
     * Our virtual destructor.
     */
    linear_fm_waveform_impl::~linear_fm_waveform_impl()
    {
    }

    void
    linear_fm_waveform_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
    #pragma message("implement a forecast that fills in how many items on each input you need to produce noutput_items and remove this warning")
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    linear_fm_waveform_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      auto in = static_cast<const input_type*>(input_items[0]);
      auto out = static_cast<output_type*>(output_items[0]);

      #pragma message("Implement the signal processing in your block and remove this warning")
      // Do <+signal processing+>
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace plasma */
} /* namespace gr */
