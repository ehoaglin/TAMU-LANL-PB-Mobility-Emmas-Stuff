// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dingo_control_msg:msg/ArmAngle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_control_msg/msg/arm_angle.hpp"


#ifndef DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__TRAITS_HPP_
#define DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dingo_control_msg/msg/detail/arm_angle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dingo_control_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArmAngle & msg,
  std::ostream & out)
{
  out << "{";
  // member: theta1
  {
    out << "theta1: ";
    rosidl_generator_traits::value_to_yaml(msg.theta1, out);
    out << ", ";
  }

  // member: theta2
  {
    out << "theta2: ";
    rosidl_generator_traits::value_to_yaml(msg.theta2, out);
    out << ", ";
  }

  // member: theta3
  {
    out << "theta3: ";
    rosidl_generator_traits::value_to_yaml(msg.theta3, out);
    out << ", ";
  }

  // member: theta4
  {
    out << "theta4: ";
    rosidl_generator_traits::value_to_yaml(msg.theta4, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmAngle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: theta1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta1: ";
    rosidl_generator_traits::value_to_yaml(msg.theta1, out);
    out << "\n";
  }

  // member: theta2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta2: ";
    rosidl_generator_traits::value_to_yaml(msg.theta2, out);
    out << "\n";
  }

  // member: theta3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta3: ";
    rosidl_generator_traits::value_to_yaml(msg.theta3, out);
    out << "\n";
  }

  // member: theta4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta4: ";
    rosidl_generator_traits::value_to_yaml(msg.theta4, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmAngle & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace dingo_control_msg

namespace rosidl_generator_traits
{

[[deprecated("use dingo_control_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dingo_control_msg::msg::ArmAngle & msg,
  std::ostream & out, size_t indentation = 0)
{
  dingo_control_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dingo_control_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const dingo_control_msg::msg::ArmAngle & msg)
{
  return dingo_control_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dingo_control_msg::msg::ArmAngle>()
{
  return "dingo_control_msg::msg::ArmAngle";
}

template<>
inline const char * name<dingo_control_msg::msg::ArmAngle>()
{
  return "dingo_control_msg/msg/ArmAngle";
}

template<>
struct has_fixed_size<dingo_control_msg::msg::ArmAngle>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dingo_control_msg::msg::ArmAngle>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dingo_control_msg::msg::ArmAngle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__TRAITS_HPP_
