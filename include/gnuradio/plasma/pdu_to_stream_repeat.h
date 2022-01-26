/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PLASMA_PDU_TO_STREAM_REPEAT_H
#define INCLUDED_PLASMA_PDU_TO_STREAM_REPEAT_H

#include <gnuradio/plasma/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace plasma {

    /*!
     * \brief <+description of block+>
     * \ingroup plasma
     *
     */
    class PLASMA_API pdu_to_stream_repeat : virtual public gr::sync_block
    {
     public:
      typedef std::shared_ptr<pdu_to_stream_repeat> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of plasma::pdu_to_stream_repeat.
       *
       * To avoid accidental use of raw pointers, plasma::pdu_to_stream_repeat's
       * constructor is in a private implementation
       * class. plasma::pdu_to_stream_repeat::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace plasma
} // namespace gr

#endif /* INCLUDED_PLASMA_PDU_TO_STREAM_REPEAT_H */
