// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dingo_control_msg:msg/TaskSpace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_control_msg/msg/task_space.hpp"


#ifndef DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__STRUCT_HPP_
#define DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dingo_control_msg__msg__TaskSpace __attribute__((deprecated))
#else
# define DEPRECATED__dingo_control_msg__msg__TaskSpace __declspec(deprecated)
#endif

namespace dingo_control_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TaskSpace_
{
  using Type = TaskSpace_<ContainerAllocator>;

  explicit TaskSpace_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->fl_foot.begin(), this->fl_foot.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->fr_foot.begin(), this->fr_foot.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rl_foot.begin(), this->rl_foot.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rr_foot.begin(), this->rr_foot.end(), 0.0);
    }
  }

  explicit TaskSpace_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    fl_foot(_alloc),
    fr_foot(_alloc),
    rl_foot(_alloc),
    rr_foot(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->fl_foot.begin(), this->fl_foot.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->fr_foot.begin(), this->fr_foot.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rl_foot.begin(), this->rl_foot.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rr_foot.begin(), this->rr_foot.end(), 0.0);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _fl_foot_type =
    std::array<double, 3>;
  _fl_foot_type fl_foot;
  using _fr_foot_type =
    std::array<double, 3>;
  _fr_foot_type fr_foot;
  using _rl_foot_type =
    std::array<double, 3>;
  _rl_foot_type rl_foot;
  using _rr_foot_type =
    std::array<double, 3>;
  _rr_foot_type rr_foot;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__fl_foot(
    const std::array<double, 3> & _arg)
  {
    this->fl_foot = _arg;
    return *this;
  }
  Type & set__fr_foot(
    const std::array<double, 3> & _arg)
  {
    this->fr_foot = _arg;
    return *this;
  }
  Type & set__rl_foot(
    const std::array<double, 3> & _arg)
  {
    this->rl_foot = _arg;
    return *this;
  }
  Type & set__rr_foot(
    const std::array<double, 3> & _arg)
  {
    this->rr_foot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dingo_control_msg::msg::TaskSpace_<ContainerAllocator> *;
  using ConstRawPtr =
    const dingo_control_msg::msg::TaskSpace_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dingo_control_msg::msg::TaskSpace_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dingo_control_msg::msg::TaskSpace_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dingo_control_msg::msg::TaskSpace_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dingo_control_msg::msg::TaskSpace_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dingo_control_msg::msg::TaskSpace_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dingo_control_msg::msg::TaskSpace_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dingo_control_msg::msg::TaskSpace_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dingo_control_msg::msg::TaskSpace_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dingo_control_msg__msg__TaskSpace
    std::shared_ptr<dingo_control_msg::msg::TaskSpace_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dingo_control_msg__msg__TaskSpace
    std::shared_ptr<dingo_control_msg::msg::TaskSpace_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskSpace_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->fl_foot != other.fl_foot) {
      return false;
    }
    if (this->fr_foot != other.fr_foot) {
      return false;
    }
    if (this->rl_foot != other.rl_foot) {
      return false;
    }
    if (this->rr_foot != other.rr_foot) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskSpace_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskSpace_

// alias to use template instance with default allocator
using TaskSpace =
  dingo_control_msg::msg::TaskSpace_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dingo_control_msg

#endif  // DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__STRUCT_HPP_
