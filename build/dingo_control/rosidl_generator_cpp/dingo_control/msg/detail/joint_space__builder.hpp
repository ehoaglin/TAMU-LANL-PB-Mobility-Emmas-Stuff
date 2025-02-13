// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dingo_control:msg/JointSpace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_control/msg/joint_space.hpp"


#ifndef DINGO_CONTROL__MSG__DETAIL__JOINT_SPACE__BUILDER_HPP_
#define DINGO_CONTROL__MSG__DETAIL__JOINT_SPACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dingo_control/msg/detail/joint_space__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dingo_control
{

namespace msg
{

namespace builder
{

class Init_JointSpace_rr_foot
{
public:
  explicit Init_JointSpace_rr_foot(::dingo_control::msg::JointSpace & msg)
  : msg_(msg)
  {}
  ::dingo_control::msg::JointSpace rr_foot(::dingo_control::msg::JointSpace::_rr_foot_type arg)
  {
    msg_.rr_foot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dingo_control::msg::JointSpace msg_;
};

class Init_JointSpace_rl_foot
{
public:
  explicit Init_JointSpace_rl_foot(::dingo_control::msg::JointSpace & msg)
  : msg_(msg)
  {}
  Init_JointSpace_rr_foot rl_foot(::dingo_control::msg::JointSpace::_rl_foot_type arg)
  {
    msg_.rl_foot = std::move(arg);
    return Init_JointSpace_rr_foot(msg_);
  }

private:
  ::dingo_control::msg::JointSpace msg_;
};

class Init_JointSpace_fr_foot
{
public:
  explicit Init_JointSpace_fr_foot(::dingo_control::msg::JointSpace & msg)
  : msg_(msg)
  {}
  Init_JointSpace_rl_foot fr_foot(::dingo_control::msg::JointSpace::_fr_foot_type arg)
  {
    msg_.fr_foot = std::move(arg);
    return Init_JointSpace_rl_foot(msg_);
  }

private:
  ::dingo_control::msg::JointSpace msg_;
};

class Init_JointSpace_fl_foot
{
public:
  explicit Init_JointSpace_fl_foot(::dingo_control::msg::JointSpace & msg)
  : msg_(msg)
  {}
  Init_JointSpace_fr_foot fl_foot(::dingo_control::msg::JointSpace::_fl_foot_type arg)
  {
    msg_.fl_foot = std::move(arg);
    return Init_JointSpace_fr_foot(msg_);
  }

private:
  ::dingo_control::msg::JointSpace msg_;
};

class Init_JointSpace_header
{
public:
  Init_JointSpace_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointSpace_fl_foot header(::dingo_control::msg::JointSpace::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_JointSpace_fl_foot(msg_);
  }

private:
  ::dingo_control::msg::JointSpace msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dingo_control::msg::JointSpace>()
{
  return dingo_control::msg::builder::Init_JointSpace_header();
}

}  // namespace dingo_control

#endif  // DINGO_CONTROL__MSG__DETAIL__JOINT_SPACE__BUILDER_HPP_
