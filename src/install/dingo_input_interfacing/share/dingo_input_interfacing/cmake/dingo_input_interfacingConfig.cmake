# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dingo_input_interfacing_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dingo_input_interfacing_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dingo_input_interfacing_FOUND FALSE)
  elseif(NOT dingo_input_interfacing_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dingo_input_interfacing_FOUND FALSE)
  endif()
  return()
endif()
set(_dingo_input_interfacing_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dingo_input_interfacing_FIND_QUIETLY)
  message(STATUS "Found dingo_input_interfacing: 0.0.0 (${dingo_input_interfacing_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dingo_input_interfacing' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT dingo_input_interfacing_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dingo_input_interfacing_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dingo_input_interfacing_DIR}/${_extra}")
endforeach()
