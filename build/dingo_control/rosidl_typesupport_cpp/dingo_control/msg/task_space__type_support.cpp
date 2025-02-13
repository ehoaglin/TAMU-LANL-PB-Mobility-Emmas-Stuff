// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from dingo_control:msg/TaskSpace.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "dingo_control/msg/detail/task_space__functions.h"
#include "dingo_control/msg/detail/task_space__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace dingo_control
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskSpace_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskSpace_type_support_ids_t;

static const _TaskSpace_type_support_ids_t _TaskSpace_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskSpace_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskSpace_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskSpace_type_support_symbol_names_t _TaskSpace_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dingo_control, msg, TaskSpace)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dingo_control, msg, TaskSpace)),
  }
};

typedef struct _TaskSpace_type_support_data_t
{
  void * data[2];
} _TaskSpace_type_support_data_t;

static _TaskSpace_type_support_data_t _TaskSpace_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskSpace_message_typesupport_map = {
  2,
  "dingo_control",
  &_TaskSpace_message_typesupport_ids.typesupport_identifier[0],
  &_TaskSpace_message_typesupport_symbol_names.symbol_name[0],
  &_TaskSpace_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskSpace_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskSpace_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &dingo_control__msg__TaskSpace__get_type_hash,
  &dingo_control__msg__TaskSpace__get_type_description,
  &dingo_control__msg__TaskSpace__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace dingo_control

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dingo_control::msg::TaskSpace>()
{
  return &::dingo_control::msg::rosidl_typesupport_cpp::TaskSpace_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, dingo_control, msg, TaskSpace)() {
  return get_message_type_support_handle<dingo_control::msg::TaskSpace>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
