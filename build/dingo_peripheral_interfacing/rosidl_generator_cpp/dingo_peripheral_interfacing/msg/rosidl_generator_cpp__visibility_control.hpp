// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef DINGO_PERIPHERAL_INTERFACING__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define DINGO_PERIPHERAL_INTERFACING__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_dingo_peripheral_interfacing __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_dingo_peripheral_interfacing __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_dingo_peripheral_interfacing __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_dingo_peripheral_interfacing __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_dingo_peripheral_interfacing
    #define ROSIDL_GENERATOR_CPP_PUBLIC_dingo_peripheral_interfacing ROSIDL_GENERATOR_CPP_EXPORT_dingo_peripheral_interfacing
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_dingo_peripheral_interfacing ROSIDL_GENERATOR_CPP_IMPORT_dingo_peripheral_interfacing
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_dingo_peripheral_interfacing __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_dingo_peripheral_interfacing
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_dingo_peripheral_interfacing __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_dingo_peripheral_interfacing
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // DINGO_PERIPHERAL_INTERFACING__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
