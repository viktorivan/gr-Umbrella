/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_UMBRELLA_ENCODCONV_CPP_VFF_H
#define INCLUDED_UMBRELLA_ENCODCONV_CPP_VFF_H

#include <Umbrella/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace Umbrella {

    /*!
     * \brief <+description of block+>
     * \ingroup Umbrella
     *
     */
    class UMBRELLA_API encodconv_cpp_vff : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<encodconv_cpp_vff> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of Umbrella::encodconv_cpp_vff.
       *
       * To avoid accidental use of raw pointers, Umbrella::encodconv_cpp_vff's
       * constructor is in a private implementation
       * class. Umbrella::encodconv_cpp_vff::make is the public interface for
       * creating new instances.
       */
      static sptr make(int val1, int val2, int val3);
    };

  } // namespace Umbrella
} // namespace gr

#endif /* INCLUDED_UMBRELLA_ENCODCONV_CPP_VFF_H */

