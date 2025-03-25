// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from dingo_control:msg/Angle.idl
// generated code does not contain a copyright notice

#include "dingo_control/msg/detail/angle__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_dingo_control
const rosidl_type_hash_t *
dingo_control__msg__Angle__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0a, 0xdf, 0x6d, 0xc9, 0xd7, 0x02, 0x24, 0xd5,
      0x6f, 0x80, 0x46, 0x74, 0x37, 0xc0, 0x49, 0x1d,
      0xf3, 0xb1, 0x1e, 0x1d, 0x9b, 0x81, 0xcc, 0x56,
      0xb4, 0x9e, 0x6f, 0x6d, 0xe3, 0x84, 0x37, 0x71,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char dingo_control__msg__Angle__TYPE_NAME[] = "dingo_control/msg/Angle";

// Define type names, field names, and default values
static char dingo_control__msg__Angle__FIELD_NAME__theta1[] = "theta1";
static char dingo_control__msg__Angle__FIELD_NAME__theta2[] = "theta2";
static char dingo_control__msg__Angle__FIELD_NAME__theta3[] = "theta3";

static rosidl_runtime_c__type_description__Field dingo_control__msg__Angle__FIELDS[] = {
  {
    {dingo_control__msg__Angle__FIELD_NAME__theta1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_control__msg__Angle__FIELD_NAME__theta2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_control__msg__Angle__FIELD_NAME__theta3, 6, 6},
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
dingo_control__msg__Angle__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dingo_control__msg__Angle__TYPE_NAME, 23, 23},
      {dingo_control__msg__Angle__FIELDS, 3, 3},
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
  "float32 theta3";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
dingo_control__msg__Angle__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dingo_control__msg__Angle__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 45, 45},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dingo_control__msg__Angle__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dingo_control__msg__Angle__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
