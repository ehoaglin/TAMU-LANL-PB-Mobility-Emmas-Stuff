// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dingo_control_msg:msg/JointSpace.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dingo_control_msg/msg/detail/joint_space__rosidl_typesupport_introspection_c.h"
#include "dingo_control_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dingo_control_msg/msg/detail/joint_space__functions.h"
#include "dingo_control_msg/msg/detail/joint_space__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `fl_foot`
// Member `fr_foot`
// Member `rl_foot`
// Member `rr_foot`
#include "dingo_control_msg/msg/angle.h"
// Member `fl_foot`
// Member `fr_foot`
// Member `rl_foot`
// Member `rr_foot`
#include "dingo_control_msg/msg/detail/angle__rosidl_typesupport_introspection_c.h"
// Member `exc_arm`
#include "dingo_control_msg/msg/arm_angle.h"
// Member `exc_arm`
#include "dingo_control_msg/msg/detail/arm_angle__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dingo_control_msg__msg__JointSpace__init(message_memory);
}

void dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_fini_function(void * message_memory)
{
  dingo_control_msg__msg__JointSpace__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg__msg__JointSpace, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fl_foot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg__msg__JointSpace, fl_foot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fr_foot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg__msg__JointSpace, fr_foot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rl_foot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg__msg__JointSpace, rl_foot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rr_foot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg__msg__JointSpace, rr_foot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "exc_arm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_control_msg__msg__JointSpace, exc_arm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_members = {
  "dingo_control_msg__msg",  // message namespace
  "JointSpace",  // message name
  6,  // number of fields
  sizeof(dingo_control_msg__msg__JointSpace),
  false,  // has_any_key_member_
  dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_member_array,  // message members
  dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_init_function,  // function to initialize message memory (memory has to be allocated)
  dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_type_support_handle = {
  0,
  &dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_members,
  get_message_typesupport_handle_function,
  &dingo_control_msg__msg__JointSpace__get_type_hash,
  &dingo_control_msg__msg__JointSpace__get_type_description,
  &dingo_control_msg__msg__JointSpace__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dingo_control_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dingo_control_msg, msg, JointSpace)() {
  dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dingo_control_msg, msg, Angle)();
  dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dingo_control_msg, msg, Angle)();
  dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dingo_control_msg, msg, Angle)();
  dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dingo_control_msg, msg, Angle)();
  dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dingo_control_msg, msg, ArmAngle)();
  if (!dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_type_support_handle.typesupport_identifier) {
    dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dingo_control_msg__msg__JointSpace__rosidl_typesupport_introspection_c__JointSpace_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
