// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from dingo_control_msg:msg/ArmAngle.idl
// generated code does not contain a copyright notice

#include "dingo_control_msg/msg/detail/arm_angle__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
const rosidl_type_hash_t *
dingo_control_msg__msg__ArmAngle__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xed, 0x43, 0xdf, 0xd4, 0x37, 0xf9, 0x0c, 0x0a,
      0x8b, 0x62, 0x36, 0xcc, 0x56, 0xf1, 0xbb, 0x64,
      0x94, 0xef, 0x08, 0x26, 0x7c, 0x96, 0x1f, 0x44,
      0x25, 0xf1, 0xa5, 0xcd, 0xf2, 0x4e, 0xda, 0x25,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char dingo_control_msg__msg__ArmAngle__TYPE_NAME[] = "dingo_control_msg/msg/ArmAngle";

// Define type names, field names, and default values
static char dingo_control_msg__msg__ArmAngle__FIELD_NAME__theta1[] = "theta1";
static char dingo_control_msg__msg__ArmAngle__FIELD_NAME__theta2[] = "theta2";
static char dingo_control_msg__msg__ArmAngle__FIELD_NAME__theta3[] = "theta3";
static char dingo_control_msg__msg__ArmAngle__FIELD_NAME__theta4[] = "theta4";

static rosidl_runtime_c__type_description__Field dingo_control_msg__msg__ArmAngle__FIELDS[] = {
  {
    {dingo_control_msg__msg__ArmAngle__FIELD_NAME__theta1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_control_msg__msg__ArmAngle__FIELD_NAME__theta2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_control_msg__msg__ArmAngle__FIELD_NAME__theta3, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_control_msg__msg__ArmAngle__FIELD_NAME__theta4, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dingo_control_msg__msg__ArmAngle__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dingo_control_msg__msg__ArmAngle__TYPE_NAME, 30, 30},
      {dingo_control_msg__msg__ArmAngle__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 theta1\n"
  "float32 theta2\n"
  "float32 theta3\n"
  "float32 theta4";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
dingo_control_msg__msg__ArmAngle__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dingo_control_msg__msg__ArmAngle__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 59, 59},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dingo_control_msg__msg__ArmAngle__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dingo_control_msg__msg__ArmAngle__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
