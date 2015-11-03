/* -*- c++ -*- */

#define UMBRELLA_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "Umbrella_swig_doc.i"

%{
#include "Umbrella/bin2dec_cpp_ff.h"
#include "Umbrella/dec2bin_cpp_ff.h"
#include "Umbrella/encodconv_cpp_vff.h"
#include "Umbrella/decodconv_cpp_ff.h"
%}


%include "Umbrella/bin2dec_cpp_ff.h"
GR_SWIG_BLOCK_MAGIC2(Umbrella, bin2dec_cpp_ff);
%include "Umbrella/dec2bin_cpp_ff.h"
GR_SWIG_BLOCK_MAGIC2(Umbrella, dec2bin_cpp_ff);
%include "Umbrella/encodconv_cpp_vff.h"
GR_SWIG_BLOCK_MAGIC2(Umbrella, encodconv_cpp_vff);
%include "Umbrella/decodconv_cpp_ff.h"
GR_SWIG_BLOCK_MAGIC2(Umbrella, decodconv_cpp_ff);
