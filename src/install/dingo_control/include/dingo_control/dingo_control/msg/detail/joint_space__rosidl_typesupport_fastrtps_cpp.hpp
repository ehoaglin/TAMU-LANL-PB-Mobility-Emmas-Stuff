// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from dingo_control:msg/JointSpace.idl
// generated code does not contain a copyright notice

#ifndef DINGO_CONTROL__MSG__DETAIL__JOINT_SPACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define DINGO_CONTROL__MSG__DETAIL__JOINT_SPACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "dingo_control/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "dingo_control/msg/detail/joint_space__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace dingo_control
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control
cdr_serialize(
  const dingo_control::msg::JointSpace & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dingo_control::msg::JointSpace & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control
get_serialized_size(
  const dingo_control::msg::JointSpace & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control
max_serialized_size_JointSpace(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control
cdr_serialize_key(
  const dingo_control::msg::JointSpace & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control
get_serialized_size_key(
  const dingo_control::msg::JointSpace & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control
max_serialized_size_key_JointSpace(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace dingo_control

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dingo_control, msg, JointSpace)();

#ifdef __cplusplus
}
#endif

#endif  // DINGO_CONTROL__MSG__DETAIL__JOINT_SPACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
