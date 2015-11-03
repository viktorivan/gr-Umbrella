INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_UMBRELLA Umbrella)

FIND_PATH(
    UMBRELLA_INCLUDE_DIRS
    NAMES Umbrella/api.h
    HINTS $ENV{UMBRELLA_DIR}/include
        ${PC_UMBRELLA_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    UMBRELLA_LIBRARIES
    NAMES gnuradio-Umbrella
    HINTS $ENV{UMBRELLA_DIR}/lib
        ${PC_UMBRELLA_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(UMBRELLA DEFAULT_MSG UMBRELLA_LIBRARIES UMBRELLA_INCLUDE_DIRS)
MARK_AS_ADVANCED(UMBRELLA_LIBRARIES UMBRELLA_INCLUDE_DIRS)

