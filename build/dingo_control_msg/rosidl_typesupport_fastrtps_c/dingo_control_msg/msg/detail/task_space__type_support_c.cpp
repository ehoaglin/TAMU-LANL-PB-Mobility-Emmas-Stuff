// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dingo_control_msg:msg/TaskSpace.idl
// generated code does not contain a copyright notice
#include "dingo_control_msg/msg/detail/task_space__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dingo_control_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dingo_control_msg/msg/detail/task_space__struct.h"
#include "dingo_control_msg/msg/detail/task_space__functions.h"
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

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_control_msg
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_control_msg
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_control_msg
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_control_msg
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_control_msg
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_control_msg
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_control_msg
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dingo_control_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _TaskSpace__ros_msg_type = dingo_control_msg__msg__TaskSpace;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
bool cdr_serialize_dingo_control_msg__msg__TaskSpace(
  const dingo_control_msg__msg__TaskSpace * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: fl_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->fl_foot;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: fr_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->fr_foot;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: rl_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->rl_foot;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: rr_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->rr_foot;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
bool cdr_deserialize_dingo_control_msg__msg__TaskSpace(
  eprosima::fastcdr::Cdr & cdr,
  dingo_control_msg__msg__TaskSpace * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: fl_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->fl_foot;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: fr_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->fr_foot;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: rl_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->rl_foot;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: rr_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->rr_foot;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
size_t get_serialized_size_dingo_control_msg__msg__TaskSpace(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TaskSpace__ros_msg_type * ros_message = static_cast<const _TaskSpace__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: fl_foot
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->fl_foot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: fr_foot
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->fr_foot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rl_foot
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->rl_foot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rr_foot
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->rr_foot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
size_t max_serialized_size_dingo_control_msg__msg__TaskSpace(
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

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: fl_foot
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: fr_foot
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: rl_foot
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: rr_foot
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dingo_control_msg__msg__TaskSpace;
    is_plain =
      (
      offsetof(DataType, rr_foot) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
bool cdr_serialize_key_dingo_control_msg__msg__TaskSpace(
  const dingo_control_msg__msg__TaskSpace * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: fl_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->fl_foot;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: fr_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->fr_foot;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: rl_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->rl_foot;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: rr_foot
  {
    size_t size = 3;
    auto array_ptr = ros_message->rr_foot;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
size_t get_serialized_size_key_dingo_control_msg__msg__TaskSpace(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TaskSpace__ros_msg_type * ros_message = static_cast<const _TaskSpace__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: fl_foot
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->fl_foot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: fr_foot
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->fr_foot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rl_foot
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->rl_foot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rr_foot
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->rr_foot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_control_msg
size_t max_serialized_size_key_dingo_control_msg__msg__TaskSpace(
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
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: fl_foot
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: fr_foot
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: rl_foot
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: rr_foot
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dingo_control_msg__msg__TaskSpace;
    is_plain =
      (
      offsetof(DataType, rr_foot) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _TaskSpace__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const dingo_control_msg__msg__TaskSpace * ros_message = static_cast<const dingo_control_msg__msg__TaskSpace *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_dingo_control_msg__msg__TaskSpace(ros_message, cdr);
}

static bool _TaskSpace__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  dingo_control_msg__msg__TaskSpace * ros_message = static_cast<dingo_control_msg__msg__TaskSpace *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_dingo_control_msg__msg__TaskSpace(cdr, ros_message);
}

static uint32_t _TaskSpace__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dingo_control_msg__msg__TaskSpace(
      untyped_ros_message, 0));
}

static size_t _TaskSpace__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dingo_control_msg__msg__TaskSpace(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TaskSpace = {
  "dingo_control_msg::msg",
  "TaskSpace",
  _TaskSpace__cdr_serialize,
  _TaskSpace__cdr_deserialize,
  _TaskSpace__get_serialized_size,
  _TaskSpace__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _TaskSpace__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TaskSpace,
  get_message_typesupport_handle_function,
  &dingo_control_msg__msg__TaskSpace__get_type_hash,
  &dingo_control_msg__msg__TaskSpace__get_type_description,
  &dingo_control_msg__msg__TaskSpace__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dingo_control_msg, msg, TaskSpace)() {
  return &_TaskSpace__type_support;
}

#if defined(__cplusplus)
}
#endif
