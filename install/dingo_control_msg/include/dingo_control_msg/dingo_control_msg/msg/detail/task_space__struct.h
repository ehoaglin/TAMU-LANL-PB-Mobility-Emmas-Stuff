// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dingo_control_msg:msg/TaskSpace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_control_msg/msg/task_space.h"


#ifndef DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__STRUCT_H_
#define DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/TaskSpace in the package dingo_control_msg.
typedef struct dingo_control_msg__msg__TaskSpace
{
  std_msgs__msg__Header header;
  double fl_foot[3];
  double fr_foot[3];
  double rl_foot[3];
  double rr_foot[3];
} dingo_control_msg__msg__TaskSpace;

// Struct for a sequence of dingo_control_msg__msg__TaskSpace.
typedef struct dingo_control_msg__msg__TaskSpace__Sequence
{
  dingo_control_msg__msg__TaskSpace * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dingo_control_msg__msg__TaskSpace__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__STRUCT_H_
