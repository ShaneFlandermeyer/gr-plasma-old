find_package(PkgConfig)

PKG_CHECK_MODULES(PC_PLASMA plasma)

FIND_PATH(
    PLASMA_INCLUDE_DIRS
    NAMES plasma/api.h
    HINTS $ENV{PLASMA_DIR}/include
        ${PC_PLASMA_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    PLASMA_LIBRARIES
    NAMES gnuradio-plasma
    HINTS $ENV{PLASMA_DIR}/lib
        ${PC_PLASMA_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/plasmaTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PLASMA DEFAULT_MSG PLASMA_LIBRARIES PLASMA_INCLUDE_DIRS)
MARK_AS_ADVANCED(PLASMA_LIBRARIES PLASMA_INCLUDE_DIRS)
