// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dingo_control_msg:msg/ArmAngle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_control_msg/msg/arm_angle.h"


#ifndef DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__STRUCT_H_
#define DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/ArmAngle in the package dingo_control_msg.
typedef struct dingo_control_msg__msg__ArmAngle
{
  float theta1;
  float theta2;
  float theta3;
  float theta4;
} dingo_control_msg__msg__ArmAngle;

// Struct for a sequence of dingo_control_msg__msg__ArmAngle.
typedef struct dingo_control_msg__msg__ArmAngle__Sequence
{
  dingo_control_msg__msg__ArmAngle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dingo_control_msg__msg__ArmAngle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__STRUCT_H_
