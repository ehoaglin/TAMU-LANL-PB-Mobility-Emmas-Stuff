// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dingo_control_msg:msg/ArmAngle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_control_msg/msg/arm_angle.hpp"


#ifndef DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__STRUCT_HPP_
#define DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dingo_control_msg__msg__ArmAngle __attribute__((deprecated))
#else
# define DEPRECATED__dingo_control_msg__msg__ArmAngle __declspec(deprecated)
#endif

namespace dingo_control_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmAngle_
{
  using Type = ArmAngle_<ContainerAllocator>;

  explicit ArmAngle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->theta1 = 0.0f;
      this->theta2 = 0.0f;
      this->theta3 = 0.0f;
      this->theta4 = 0.0f;
    }
  }

  explicit ArmAngle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->theta1 = 0.0f;
      this->theta2 = 0.0f;
      this->theta3 = 0.0f;
      this->theta4 = 0.0f;
    }
  }

  // field types and members
  using _theta1_type =
    float;
  _theta1_type theta1;
  using _theta2_type =
    float;
  _theta2_type theta2;
  using _theta3_type =
    float;
  _theta3_type theta3;
  using _theta4_type =
    float;
  _theta4_type theta4;

  // setters for named parameter idiom
  Type & set__theta1(
    const float & _arg)
  {
    this->theta1 = _arg;
    return *this;
  }
  Type & set__theta2(
    const float & _arg)
  {
    this->theta2 = _arg;
    return *this;
  }
  Type & set__theta3(
    const float & _arg)
  {
    this->theta3 = _arg;
    return *this;
  }
  Type & set__theta4(
    const float & _arg)
  {
    this->theta4 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dingo_control_msg::msg::ArmAngle_<ContainerAllocator> *;
  using ConstRawPtr =
    const dingo_control_msg::msg::ArmAngle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dingo_control_msg::msg::ArmAngle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dingo_control_msg::msg::ArmAngle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dingo_control_msg::msg::ArmAngle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dingo_control_msg::msg::ArmAngle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dingo_control_msg::msg::ArmAngle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dingo_control_msg::msg::ArmAngle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dingo_control_msg::msg::ArmAngle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dingo_control_msg::msg::ArmAngle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dingo_control_msg__msg__ArmAngle
    std::shared_ptr<dingo_control_msg::msg::ArmAngle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dingo_control_msg__msg__ArmAngle
    std::shared_ptr<dingo_control_msg::msg::ArmAngle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmAngle_ & other) const
  {
    if (this->theta1 != other.theta1) {
      return false;
    }
    if (this->theta2 != other.theta2) {
      return false;
    }
    if (this->theta3 != other.theta3) {
      return false;
    }
    if (this->theta4 != other.theta4) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmAngle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmAngle_

// alias to use template instance with default allocator
using ArmAngle =
  dingo_control_msg::msg::ArmAngle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dingo_control_msg

#endif  // DINGO_CONTROL_MSG__MSG__DETAIL__ARM_ANGLE__STRUCT_HPP_
