/* -*- c++ -*- */
/* 
 * Copyright 2015 IVAN RODRIGUEZ.
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

#ifndef INCLUDED_UMBRELLA_ENCODCONV_CPP_VFF_IMPL_H
#define INCLUDED_UMBRELLA_ENCODCONV_CPP_VFF_IMPL_H

#include <Umbrella/encodconv_cpp_vff.h>
#include <itpp/itcomm.h>

namespace gr {
  namespace Umbrella {

    class encodconv_cpp_vff_impl : public encodconv_cpp_vff
    {
     private:
      // Nothing to declare in this block.

     public:
      encodconv_cpp_vff_impl(int val1, int val2, int val3);
      unsigned char polynom [0x100];
      int polsize;
      int cl;
      int pz;
      itpp::Convolutional_Code code;

      ~encodconv_cpp_vff_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace Umbrella
} // namespace gr

#endif /* INCLUDED_UMBRELLA_ENCODCONV_CPP_VFF_IMPL_H */

