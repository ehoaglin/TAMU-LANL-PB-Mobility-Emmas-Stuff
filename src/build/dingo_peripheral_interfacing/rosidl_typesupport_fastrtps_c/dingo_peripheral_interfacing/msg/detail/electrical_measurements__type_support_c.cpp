// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dingo_peripheral_interfacing:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice
#include "dingo_peripheral_interfacing/msg/detail/electrical_measurements__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dingo_peripheral_interfacing/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dingo_peripheral_interfacing/msg/detail/electrical_measurements__struct.h"
#include "dingo_peripheral_interfacing/msg/detail/electrical_measurements__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ElectricalMeasurements__ros_msg_type = dingo_peripheral_interfacing__msg__ElectricalMeasurements;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
bool cdr_serialize_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  const dingo_peripheral_interfacing__msg__ElectricalMeasurements * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: battery_voltage_level
  {
    cdr << ros_message->battery_voltage_level;
  }

  // Field name: servo_buck_voltage_level
  {
    cdr << ros_message->servo_buck_voltage_level;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
bool cdr_deserialize_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  eprosima::fastcdr::Cdr & cdr,
  dingo_peripheral_interfacing__msg__ElectricalMeasurements * ros_message)
{
  // Field name: battery_voltage_level
  {
    cdr >> ros_message->battery_voltage_level;
  }

  // Field name: servo_buck_voltage_level
  {
    cdr >> ros_message->servo_buck_voltage_level;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
size_t get_serialized_size_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ElectricalMeasurements__ros_msg_type * ros_message = static_cast<const _ElectricalMeasurements__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: battery_voltage_level
  {
    size_t item_size = sizeof(ros_message->battery_voltage_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: servo_buck_voltage_level
  {
    size_t item_size = sizeof(ros_message->servo_buck_voltage_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
size_t max_serialized_size_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: battery_voltage_level
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: servo_buck_voltage_level
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dingo_peripheral_interfacing__msg__ElectricalMeasurements;
    is_plain =
      (
      offsetof(DataType, servo_buck_voltage_level) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
bool cdr_serialize_key_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  const dingo_peripheral_interfacing__msg__ElectricalMeasurements * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: battery_voltage_level
  {
    cdr << ros_message->battery_voltage_level;
  }

  // Field name: servo_buck_voltage_level
  {
    cdr << ros_message->servo_buck_voltage_level;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
size_t get_serialized_size_key_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ElectricalMeasurements__ros_msg_type * ros_message = static_cast<const _ElectricalMeasurements__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: battery_voltage_level
  {
    size_t item_size = sizeof(ros_message->battery_voltage_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: servo_buck_voltage_level
  {
    size_t item_size = sizeof(ros_message->servo_buck_voltage_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_peripheral_interfacing
size_t max_serialized_size_key_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: battery_voltage_level
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: servo_buck_voltage_level
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dingo_peripheral_interfacing__msg__ElectricalMeasurements;
    is_plain =
      (
      offsetof(DataType, servo_buck_voltage_level) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ElectricalMeasurements__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const dingo_peripheral_interfacing__msg__ElectricalMeasurements * ros_message = static_cast<const dingo_peripheral_interfacing__msg__ElectricalMeasurements *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_dingo_peripheral_interfacing__msg__ElectricalMeasurements(ros_message, cdr);
}

static bool _ElectricalMeasurements__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  dingo_peripheral_interfacing__msg__ElectricalMeasurements * ros_message = static_cast<dingo_peripheral_interfacing__msg__ElectricalMeasurements *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_dingo_peripheral_interfacing__msg__ElectricalMeasurements(cdr, ros_message);
}

static uint32_t _ElectricalMeasurements__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
      untyped_ros_message, 0));
}

static size_t _ElectricalMeasurements__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dingo_peripheral_interfacing__msg__ElectricalMeasurements(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ElectricalMeasurements = {
  "dingo_peripheral_interfacing::msg",
  "ElectricalMeasurements",
  _ElectricalMeasurements__cdr_serialize,
  _ElectricalMeasurements__cdr_deserialize,
  _ElectricalMeasurements__get_serialized_size,
  _ElectricalMeasurements__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ElectricalMeasurements__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ElectricalMeasurements,
  get_message_typesupport_handle_function,
  &dingo_peripheral_interfacing__msg__ElectricalMeasurements__get_type_hash,
  &dingo_peripheral_interfacing__msg__ElectricalMeasurements__get_type_description,
  &dingo_peripheral_interfacing__msg__ElectricalMeasurements__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dingo_peripheral_interfacing, msg, ElectricalMeasurements)() {
  return &_ElectricalMeasurements__type_support;
}

#if defined(__cplusplus)
}
#endif
