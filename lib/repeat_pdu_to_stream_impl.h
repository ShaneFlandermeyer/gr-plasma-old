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
    size_t d_curr_index;
    bool d_has_pdu;
    std::vector<gr_complex> d_data;
    pmt::pmt_t d_pdu;

public:
    repeat_pdu_to_stream_impl();
    ~repeat_pdu_to_stream_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);

    /**
     * @brief Tell the block that a PDU has been received (and store it), but don't
     * actually modify the data buffer yet.
     *
     * @param msg
     */
    void handle_msg(const pmt::pmt_t& msg);

    /**
     * @brief Store the PDU data in the data class member
     *
     * @param pdu
     */
    void store_pdu(const pmt::pmt_t& pdu);
};

} // namespace plasma
} // namespace gr

#endif /* INCLUDED_PLASMA_REPEAT_PDU_TO_STREAM_IMPL_H */
