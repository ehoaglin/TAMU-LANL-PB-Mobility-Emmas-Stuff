// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from dingo_peripheral_interfacing_msg:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice

#include "dingo_peripheral_interfacing_msg/msg/detail/electrical_measurements__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_dingo_peripheral_interfacing_msg
const rosidl_type_hash_t *
dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8f, 0x74, 0x29, 0x5b, 0x44, 0x55, 0xef, 0x30,
      0x04, 0xd7, 0x4a, 0xa9, 0x4f, 0x54, 0x93, 0xc4,
      0xc4, 0xb8, 0x15, 0x7d, 0xe3, 0x50, 0xd3, 0xc3,
      0x12, 0x58, 0xaa, 0xab, 0xa0, 0x0c, 0x6d, 0xda,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__TYPE_NAME[] = "dingo_peripheral_interfacing_msg/msg/ElectricalMeasurements";

// Define type names, field names, and default values
static char dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__FIELD_NAME__battery_voltage_level[] = "battery_voltage_level";
static char dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__FIELD_NAME__servo_buck_voltage_level[] = "servo_buck_voltage_level";

static rosidl_runtime_c__type_description__Field dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__FIELDS[] = {
  {
    {dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__FIELD_NAME__battery_voltage_level, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__FIELD_NAME__servo_buck_voltage_level, 24, 24},
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
dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__TYPE_NAME, 59, 59},
      {dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 battery_voltage_level\n"
  "float32 servo_buck_voltage_level";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__TYPE_NAME, 59, 59},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 63, 63},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dingo_peripheral_interfacing_msg__msg__ElectricalMeasurements__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
