// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dingo_control_msg:msg/TaskSpace.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dingo_control_msg/msg/detail/task_space__functions.h"
#include "dingo_control_msg/msg/detail/task_space__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dingo_control_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TaskSpace_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dingo_control_msg::msg::TaskSpace(_init);
}

void TaskSpace_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dingo_control_msg::msg::TaskSpace *>(message_memory);
  typed_message->~TaskSpace();
}

size_t size_function__TaskSpace__fl_foot(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__TaskSpace__fl_foot(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__TaskSpace__fl_foot(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__TaskSpace__fl_foot(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__TaskSpace__fl_foot(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__TaskSpace__fl_foot(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__TaskSpace__fl_foot(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__TaskSpace__fr_foot(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__TaskSpace__fr_foot(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__TaskSpace__fr_foot(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__TaskSpace__fr_foot(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__TaskSpace__fr_foot(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__TaskSpace__fr_foot(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__TaskSpace__fr_foot(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__TaskSpace__rl_foot(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__TaskSpace__rl_foot(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__TaskSpace__rl_foot(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__TaskSpace__rl_foot(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__TaskSpace__rl_foot(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__TaskSpace__rl_foot(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__TaskSpace__rl_foot(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__TaskSpace__rr_foot(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__TaskSpace__rr_foot(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__TaskSpace__rr_foot(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__TaskSpace__rr_foot(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__TaskSpace__rr_foot(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__TaskSpace__rr_foot(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__TaskSpace__rr_foot(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TaskSpace_message_member_array[5] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg::msg::TaskSpace, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "fl_foot",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg::msg::TaskSpace, fl_foot),  // bytes offset in struct
    nullptr,  // default value
    size_function__TaskSpace__fl_foot,  // size() function pointer
    get_const_function__TaskSpace__fl_foot,  // get_const(index) function pointer
    get_function__TaskSpace__fl_foot,  // get(index) function pointer
    fetch_function__TaskSpace__fl_foot,  // fetch(index, &value) function pointer
    assign_function__TaskSpace__fl_foot,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "fr_foot",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg::msg::TaskSpace, fr_foot),  // bytes offset in struct
    nullptr,  // default value
    size_function__TaskSpace__fr_foot,  // size() function pointer
    get_const_function__TaskSpace__fr_foot,  // get_const(index) function pointer
    get_function__TaskSpace__fr_foot,  // get(index) function pointer
    fetch_function__TaskSpace__fr_foot,  // fetch(index, &value) function pointer
    assign_function__TaskSpace__fr_foot,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rl_foot",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg::msg::TaskSpace, rl_foot),  // bytes offset in struct
    nullptr,  // default value
    size_function__TaskSpace__rl_foot,  // size() function pointer
    get_const_function__TaskSpace__rl_foot,  // get_const(index) function pointer
    get_function__TaskSpace__rl_foot,  // get(index) function pointer
    fetch_function__TaskSpace__rl_foot,  // fetch(index, &value) function pointer
    assign_function__TaskSpace__rl_foot,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rr_foot",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg::msg::TaskSpace, rr_foot),  // bytes offset in struct
    nullptr,  // default value
    size_function__TaskSpace__rr_foot,  // size() function pointer
    get_const_function__TaskSpace__rr_foot,  // get_const(index) function pointer
    get_function__TaskSpace__rr_foot,  // get(index) function pointer
    fetch_function__TaskSpace__rr_foot,  // fetch(index, &value) function pointer
    assign_function__TaskSpace__rr_foot,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TaskSpace_message_members = {
  "dingo_control_msg::msg",  // message namespace
  "TaskSpace",  // message name
  5,  // number of fields
  sizeof(dingo_control_msg::msg::TaskSpace),
  false,  // has_any_key_member_
  TaskSpace_message_member_array,  // message members
  TaskSpace_init_function,  // function to initialize message memory (memory has to be allocated)
  TaskSpace_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TaskSpace_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TaskSpace_message_members,
  get_message_typesupport_handle_function,
  &dingo_control_msg__msg__TaskSpace__get_type_hash,
  &dingo_control_msg__msg__TaskSpace__get_type_description,
  &dingo_control_msg__msg__TaskSpace__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dingo_control_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dingo_control_msg::msg::TaskSpace>()
{
  return &::dingo_control_msg::msg::rosidl_typesupport_introspection_cpp::TaskSpace_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dingo_control_msg, msg, TaskSpace)() {
  return &::dingo_control_msg::msg::rosidl_typesupport_introspection_cpp::TaskSpace_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
