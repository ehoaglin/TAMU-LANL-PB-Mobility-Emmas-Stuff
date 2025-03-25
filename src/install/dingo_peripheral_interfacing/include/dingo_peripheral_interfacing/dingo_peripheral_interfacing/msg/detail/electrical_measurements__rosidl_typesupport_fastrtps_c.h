// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from dingo_peripheral_interfacing:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice
#ifndef DINGO_PERIPHERAL_INTERFACING__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define DINGO_PERIPHERAL_INTERFACING__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "dingo_peripheral_interfacing/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dingo_peripheral_interfacing/msg/detail/electrical_measurements__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
bool cdr_serialize_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  const dingo_peripheral_interfacing__msg__ElectricalMeasurements * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
bool cdr_deserialize_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  eprosima::fastcdr::Cdr &,
  dingo_peripheral_interfacing__msg__ElectricalMeasurements * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
size_t get_serialized_size_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
size_t max_serialized_size_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
bool cdr_serialize_key_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  const dingo_peripheral_interfacing__msg__ElectricalMeasurements * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
size_t get_serialized_size_key_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
size_t max_serialized_size_key_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dingo_peripheral_interfacing, msg, ElectricalMeasurements)();

#ifdef __cplusplus
}
#endif

#endif  // DINGO_PERIPHERAL_INTERFACING__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
