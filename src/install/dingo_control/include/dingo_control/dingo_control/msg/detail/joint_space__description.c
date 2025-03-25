// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from dingo_control:msg/JointSpace.idl
// generated code does not contain a copyright notice

#include "dingo_control/msg/detail/joint_space__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_dingo_control
const rosidl_type_hash_t *
dingo_control__msg__JointSpace__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd6, 0x51, 0x64, 0x21, 0xff, 0x9b, 0x65, 0xb1,
      0x1b, 0x30, 0xa4, 0x11, 0xdf, 0x53, 0xe2, 0x65,
      0xdf, 0xaa, 0xf8, 0x7c, 0x32, 0xe1, 0x6d, 0x4c,
      0x87, 0x58, 0xf7, 0xfb, 0x06, 0xc1, 0x6b, 0xbe,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "dingo_control/msg/detail/angle__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t dingo_control__msg__Angle__EXPECTED_HASH = {1, {
    0x0a, 0xdf, 0x6d, 0xc9, 0xd7, 0x02, 0x24, 0xd5,
    0x6f, 0x80, 0x46, 0x74, 0x37, 0xc0, 0x49, 0x1d,
    0xf3, 0xb1, 0x1e, 0x1d, 0x9b, 0x81, 0xcc, 0x56,
    0xb4, 0x9e, 0x6f, 0x6d, 0xe3, 0x84, 0x37, 0x71,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char dingo_control__msg__JointSpace__TYPE_NAME[] = "dingo_control/msg/JointSpace";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char dingo_control__msg__Angle__TYPE_NAME[] = "dingo_control/msg/Angle";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char dingo_control__msg__JointSpace__FIELD_NAME__header[] = "header";
static char dingo_control__msg__JointSpace__FIELD_NAME__fl_foot[] = "fl_foot";
static char dingo_control__msg__JointSpace__FIELD_NAME__fr_foot[] = "fr_foot";
static char dingo_control__msg__JointSpace__FIELD_NAME__rl_foot[] = "rl_foot";
static char dingo_control__msg__JointSpace__FIELD_NAME__rr_foot[] = "rr_foot";

static rosidl_runtime_c__type_description__Field dingo_control__msg__JointSpace__FIELDS[] = {
  {
    {dingo_control__msg__JointSpace__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_control__msg__JointSpace__FIELD_NAME__fl_foot, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {dingo_control__msg__Angle__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_control__msg__JointSpace__FIELD_NAME__fr_foot, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {dingo_control__msg__Angle__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_control__msg__JointSpace__FIELD_NAME__rl_foot, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {dingo_control__msg__Angle__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_control__msg__JointSpace__FIELD_NAME__rr_foot, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {dingo_control__msg__Angle__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription dingo_control__msg__JointSpace__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {dingo_control__msg__Angle__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dingo_control__msg__JointSpace__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dingo_control__msg__JointSpace__TYPE_NAME, 28, 28},
      {dingo_control__msg__JointSpace__FIELDS, 5, 5},
    },
    {dingo_control__msg__JointSpace__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&dingo_control__msg__Angle__EXPECTED_HASH, dingo_control__msg__Angle__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = dingo_control__msg__Angle__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "dingo_control/Angle fl_foot\n"
  "dingo_control/Angle fr_foot\n"
  "dingo_control/Angle rl_foot\n"
  "dingo_control/Angle rr_foot";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
dingo_control__msg__JointSpace__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dingo_control__msg__JointSpace__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 135, 135},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dingo_control__msg__JointSpace__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dingo_control__msg__JointSpace__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *dingo_control__msg__Angle__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
