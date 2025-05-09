// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from dingo_control_msg:msg/ArmAngle.idl
// generated code does not contain a copyright notice
#ifndef DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "dingo_control_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dingo_control_msg/msg/detail/arm_angle__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
bool cdr_serialize_dingo_control_msg__msg__ArmAngle(
  const dingo_control_msg__msg__ArmAngle * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
bool cdr_deserialize_dingo_control_msg__msg__ArmAngle(
  eprosima::fastcdr::Cdr &,
  dingo_control_msg__msg__ArmAngle * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
size_t get_serialized_size_dingo_control_msg__msg__ArmAngle(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
size_t max_serialized_size_dingo_control_msg__msg__ArmAngle(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
bool cdr_serialize_key_dingo_control_msg__msg__ArmAngle(
  const dingo_control_msg__msg__ArmAngle * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
size_t get_serialized_size_key_dingo_control_msg__msg__ArmAngle(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
size_t max_serialized_size_key_dingo_control_msg__msg__ArmAngle(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dingo_control_msg, msg, ArmAngle)();

#ifdef __cplusplus
}
#endif

#endif  // DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
