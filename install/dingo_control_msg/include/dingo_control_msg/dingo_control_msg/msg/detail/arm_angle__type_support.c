// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dingo_control_msg:msg/ArmAngle.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dingo_control_msg/msg/detail/arm_angle__rosidl_typesupport_introspection_c.h"
#include "dingo_control_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dingo_control_msg/msg/detail/arm_angle__functions.h"
#include "dingo_control_msg/msg/detail/arm_angle__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dingo_control_msg__msg__ArmAngle__init(message_memory);
}

void dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_fini_function(void * message_memory)
{
  dingo_control_msg__msg__ArmAngle__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_message_member_array[4] = {
  {
    "theta1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg__msg__ArmAngle, theta1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg__msg__ArmAngle, theta2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg__msg__ArmAngle, theta3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg__msg__ArmAngle, theta4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_message_members = {
  "dingo_control_msg__msg",  // message namespace
  "ArmAngle",  // message name
  4,  // number of fields
  sizeof(dingo_control_msg__msg__ArmAngle),
  false,  // has_any_key_member_
  dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_message_member_array,  // message members
  dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_init_function,  // function to initialize message memory (memory has to be allocated)
  dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_message_type_support_handle = {
  0,
  &dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_message_members,
  get_message_typesupport_handle_function,
  &dingo_control_msg__msg__ArmAngle__get_type_hash,
  &dingo_control_msg__msg__ArmAngle__get_type_description,
  &dingo_control_msg__msg__ArmAngle__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dingo_control_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dingo_control_msg, msg, ArmAngle)() {
  if (!dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_message_type_support_handle.typesupport_identifier) {
    dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dingo_control_msg__msg__ArmAngle__rosidl_typesupport_introspection_c__ArmAngle_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
