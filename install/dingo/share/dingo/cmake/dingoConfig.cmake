# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dingo_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dingo_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dingo_FOUND FALSE)
  elseif(NOT dingo_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dingo_FOUND FALSE)
  endif()
  return()
endif()
set(_dingo_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dingo_FIND_QUIETLY)
  message(STATUS "Found dingo: 0.0.0 (${dingo_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dingo' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT dingo_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dingo_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dingo_DIR}/${_extra}")
endforeach()
