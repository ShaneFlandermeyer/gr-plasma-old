#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gnuradio::gnuradio-plasma" for configuration "Debug"
set_property(TARGET gnuradio::gnuradio-plasma APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gnuradio::gnuradio-plasma PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libgnuradio-plasma.so.1.0.0.0"
  IMPORTED_SONAME_DEBUG "libgnuradio-plasma.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS gnuradio::gnuradio-plasma )
list(APPEND _IMPORT_CHECK_FILES_FOR_gnuradio::gnuradio-plasma "${_IMPORT_PREFIX}/lib/libgnuradio-plasma.so.1.0.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
