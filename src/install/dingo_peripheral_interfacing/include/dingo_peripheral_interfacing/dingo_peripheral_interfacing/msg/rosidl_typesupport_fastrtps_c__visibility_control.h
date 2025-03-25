// generated from
// rosidl_typesupport_fastrtps_c/resource/rosidl_typesupport_fastrtps_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef DINGO_PERIPHERAL_INTERFACING__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
#define DINGO_PERIPHERAL_INTERFACING__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_

#if __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_dingo_peripheral_interfacing __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_peripheral_interfacing __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_dingo_peripheral_interfacing __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_peripheral_interfacing __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_FASTRTPS_C_BUILDING_DLL_dingo_peripheral_interfacing
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_dingo_peripheral_interfacing
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_peripheral_interfacing
  #endif
#else
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_dingo_peripheral_interfacing __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_peripheral_interfacing
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
  #endif
#endif

#if __cplusplus
}
#endif

#endif  // DINGO_PERIPHERAL_INTERFACING__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
