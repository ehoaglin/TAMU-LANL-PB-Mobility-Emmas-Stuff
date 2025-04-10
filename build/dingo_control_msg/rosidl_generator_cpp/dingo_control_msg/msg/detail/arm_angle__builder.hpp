// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dingo_control_msg:msg/ArmAngle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_control_msg/msg/arm_angle.hpp"


#ifndef DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__BUILDER_HPP_
#define DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dingo_control_msg/msg/detail/arm_angle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dingo_control_msg
{

namespace msg
{

namespace builder
{

class Init_ArmAngle_theta4
{
public:
  explicit Init_ArmAngle_theta4(::dingo_control_msg::msg::ArmAngle & msg)
  : msg_(msg)
  {}
  ::dingo_control_msg::msg::ArmAngle theta4(::dingo_control_msg::msg::ArmAngle::_theta4_type arg)
  {
    msg_.theta4 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dingo_control_msg::msg::ArmAngle msg_;
};

class Init_ArmAngle_theta3
{
public:
  explicit Init_ArmAngle_theta3(::dingo_control_msg::msg::ArmAngle & msg)
  : msg_(msg)
  {}
  Init_ArmAngle_theta4 theta3(::dingo_control_msg::msg::ArmAngle::_theta3_type arg)
  {
    msg_.theta3 = std::move(arg);
    return Init_ArmAngle_theta4(msg_);
  }

private:
  ::dingo_control_msg::msg::ArmAngle msg_;
};

class Init_ArmAngle_theta2
{
public:
  explicit Init_ArmAngle_theta2(::dingo_control_msg::msg::ArmAngle & msg)
  : msg_(msg)
  {}
  Init_ArmAngle_theta3 theta2(::dingo_control_msg::msg::ArmAngle::_theta2_type arg)
  {
    msg_.theta2 = std::move(arg);
    return Init_ArmAngle_theta3(msg_);
  }

private:
  ::dingo_control_msg::msg::ArmAngle msg_;
};

class Init_ArmAngle_theta1
{
public:
  Init_ArmAngle_theta1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmAngle_theta2 theta1(::dingo_control_msg::msg::ArmAngle::_theta1_type arg)
  {
    msg_.theta1 = std::move(arg);
    return Init_ArmAngle_theta2(msg_);
  }

private:
  ::dingo_control_msg::msg::ArmAngle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dingo_control_msg::msg::ArmAngle>()
{
  return dingo_control_msg::msg::builder::Init_ArmAngle_theta1();
}

}  // namespace dingo_control_msg

#endif  // DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__BUILDER_HPP_
