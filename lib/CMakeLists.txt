# Copyright 2011,2012 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

list(APPEND Umbrella_sources
    bin2dec_cpp_ff_impl.cc
    dec2bin_cpp_ff_impl.cc
    encodconv_cpp_vff_impl.cc
    decodconv_cpp_ff_impl.cc
)

set(Umbrella_sources "${Umbrella_sources}" PARENT_SCOPE)
if(NOT Umbrella_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT Umbrella_sources)

add_library(gnuradio-Umbrella SHARED ${Umbrella_sources})
target_link_libraries(gnuradio-Umbrella ${Boost_LIBRARIES} ${GNURADIO_ALL_LIBRARIES})
set_target_properties(gnuradio-Umbrella PROPERTIES DEFINE_SYMBOL "gnuradio_Umbrella_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-Umbrella PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
install(TARGETS gnuradio-Umbrella
    LIBRARY DESTINATION lib${LIB_SUFFIX} # .so/.dylib file
    ARCHIVE DESTINATION lib${LIB_SUFFIX} # .lib file
    RUNTIME DESTINATION bin              # .dll file
)

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

include_directories(${CPPUNIT_INCLUDE_DIRS})

list(APPEND test_Umbrella_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test_Umbrella.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_Umbrella.cc
)

add_executable(test-Umbrella ${test_Umbrella_sources})

target_link_libraries(
  test-Umbrella
  ${GNURADIO_RUNTIME_LIBRARIES}
  ${Boost_LIBRARIES}
  ${CPPUNIT_LIBRARIES}
  gnuradio-Umbrella
)

GR_ADD_TEST(test_Umbrella test-Umbrella)
