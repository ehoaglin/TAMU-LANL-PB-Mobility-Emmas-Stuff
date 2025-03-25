// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dingo_control:msg/JointSpace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_control/msg/joint_space.h"


#ifndef DINGO_CONTROL__MSG__DETAIL__JOINT_SPACE__STRUCT_H_
#define DINGO_CONTROL__MSG__DETAIL__JOINT_SPACE__STRUCT_H_

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
// Member 'fl_foot'
// Member 'fr_foot'
// Member 'rl_foot'
// Member 'rr_foot'
#include "dingo_control/msg/detail/angle__struct.h"

/// Struct defined in msg/JointSpace in the package dingo_control.
typedef struct dingo_control__msg__JointSpace
{
  std_msgs__msg__Header header;
  dingo_control__msg__Angle fl_foot;
  dingo_control__msg__Angle fr_foot;
  dingo_control__msg__Angle rl_foot;
  dingo_control__msg__Angle rr_foot;
} dingo_control__msg__JointSpace;

// Struct for a sequence of dingo_control__msg__JointSpace.
typedef struct dingo_control__msg__JointSpace__Sequence
{
  dingo_control__msg__JointSpace * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dingo_control__msg__JointSpace__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DINGO_CONTROL__MSG__DETAIL__JOINT_SPACE__STRUCT_H_
