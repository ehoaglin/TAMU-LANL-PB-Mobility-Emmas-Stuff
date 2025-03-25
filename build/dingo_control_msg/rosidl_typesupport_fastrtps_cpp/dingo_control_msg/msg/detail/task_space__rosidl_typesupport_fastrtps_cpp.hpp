// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from dingo_control_msg:msg/TaskSpace.idl
// generated code does not contain a copyright notice

#ifndef DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "dingo_control_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "dingo_control_msg/msg/detail/task_space__struct.hpp"

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

namespace dingo_control_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control_msg
cdr_serialize(
  const dingo_control_msg::msg::TaskSpace & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dingo_control_msg::msg::TaskSpace & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control_msg
get_serialized_size(
  const dingo_control_msg::msg::TaskSpace & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control_msg
max_serialized_size_TaskSpace(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control_msg
cdr_serialize_key(
  const dingo_control_msg::msg::TaskSpace & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control_msg
get_serialized_size_key(
  const dingo_control_msg::msg::TaskSpace & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control_msg
max_serialized_size_key_TaskSpace(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace dingo_control_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_control_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dingo_control_msg, msg, TaskSpace)();

#ifdef __cplusplus
}
#endif

#endif  // DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
