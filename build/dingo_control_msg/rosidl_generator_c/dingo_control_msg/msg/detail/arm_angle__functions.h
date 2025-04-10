// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dingo_control_msg:msg/ArmAngle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_control_msg/msg/arm_angle.h"


#ifndef DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__FUNCTIONS_H_
#define DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "dingo_control_msg/msg/rosidl_generator_c__visibility_control.h"

#include "dingo_control_msg/msg/detail/arm_angle__struct.h"

/// Initialize msg/ArmAngle message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dingo_control_msg__msg__ArmAngle
 * )) before or use
 * dingo_control_msg__msg__ArmAngle__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
bool
dingo_control_msg__msg__ArmAngle__init(dingo_control_msg__msg__ArmAngle * msg);

/// Finalize msg/ArmAngle message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
void
dingo_control_msg__msg__ArmAngle__fini(dingo_control_msg__msg__ArmAngle * msg);

/// Create msg/ArmAngle message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dingo_control_msg__msg__ArmAngle__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
dingo_control_msg__msg__ArmAngle *
dingo_control_msg__msg__ArmAngle__create(void);

/// Destroy msg/ArmAngle message.
/**
 * It calls
 * dingo_control_msg__msg__ArmAngle__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
void
dingo_control_msg__msg__ArmAngle__destroy(dingo_control_msg__msg__ArmAngle * msg);

/// Check for msg/ArmAngle message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
bool
dingo_control_msg__msg__ArmAngle__are_equal(const dingo_control_msg__msg__ArmAngle * lhs, const dingo_control_msg__msg__ArmAngle * rhs);

/// Copy a msg/ArmAngle message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
bool
dingo_control_msg__msg__ArmAngle__copy(
  const dingo_control_msg__msg__ArmAngle * input,
  dingo_control_msg__msg__ArmAngle * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
const rosidl_type_hash_t *
dingo_control_msg__msg__ArmAngle__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
const rosidl_runtime_c__type_description__TypeDescription *
dingo_control_msg__msg__ArmAngle__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
const rosidl_runtime_c__type_description__TypeSource *
dingo_control_msg__msg__ArmAngle__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
const rosidl_runtime_c__type_description__TypeSource__Sequence *
dingo_control_msg__msg__ArmAngle__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/ArmAngle messages.
/**
 * It allocates the memory for the number of elements and calls
 * dingo_control_msg__msg__ArmAngle__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
bool
dingo_control_msg__msg__ArmAngle__Sequence__init(dingo_control_msg__msg__ArmAngle__Sequence * array, size_t size);

/// Finalize array of msg/ArmAngle messages.
/**
 * It calls
 * dingo_control_msg__msg__ArmAngle__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
void
dingo_control_msg__msg__ArmAngle__Sequence__fini(dingo_control_msg__msg__ArmAngle__Sequence * array);

/// Create array of msg/ArmAngle messages.
/**
 * It allocates the memory for the array and calls
 * dingo_control_msg__msg__ArmAngle__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
dingo_control_msg__msg__ArmAngle__Sequence *
dingo_control_msg__msg__ArmAngle__Sequence__create(size_t size);

/// Destroy array of msg/ArmAngle messages.
/**
 * It calls
 * dingo_control_msg__msg__ArmAngle__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
void
dingo_control_msg__msg__ArmAngle__Sequence__destroy(dingo_control_msg__msg__ArmAngle__Sequence * array);

/// Check for msg/ArmAngle message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
bool
dingo_control_msg__msg__ArmAngle__Sequence__are_equal(const dingo_control_msg__msg__ArmAngle__Sequence * lhs, const dingo_control_msg__msg__ArmAngle__Sequence * rhs);

/// Copy an array of msg/ArmAngle messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_control_msg
bool
dingo_control_msg__msg__ArmAngle__Sequence__copy(
  const dingo_control_msg__msg__ArmAngle__Sequence * input,
  dingo_control_msg__msg__ArmAngle__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__FUNCTIONS_H_
