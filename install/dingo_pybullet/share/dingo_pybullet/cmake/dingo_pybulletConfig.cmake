# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dingo_pybullet_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dingo_pybullet_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dingo_pybullet_FOUND FALSE)
  elseif(NOT dingo_pybullet_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dingo_pybullet_FOUND FALSE)
  endif()
  return()
endif()
set(_dingo_pybullet_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dingo_pybullet_FIND_QUIETLY)
  message(STATUS "Found dingo_pybullet: 1.0.0 (${dingo_pybullet_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dingo_pybullet' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT dingo_pybullet_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dingo_pybullet_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dingo_pybullet_DIR}/${_extra}")
endforeach()
