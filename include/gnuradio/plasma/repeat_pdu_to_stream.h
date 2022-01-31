/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PLASMA_REPEAT_PDU_TO_STREAM_H
#define INCLUDED_PLASMA_REPEAT_PDU_TO_STREAM_H

#include <gnuradio/plasma/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace plasma {

/*!
 * \brief <+description of block+>
 * \ingroup plasma
 *
 */
class PLASMA_API repeat_pdu_to_stream : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<repeat_pdu_to_stream> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of plasma::repeat_pdu_to_stream.
     *
     * To avoid accidental use of raw pointers, plasma::repeat_pdu_to_stream's
     * constructor is in a private implementation
     * class. plasma::repeat_pdu_to_stream::make is the public interface for
     * creating new instances.
     */
    static sptr make();
};

} // namespace plasma
} // namespace gr

#endif /* INCLUDED_PLASMA_REPEAT_PDU_TO_STREAM_H */
