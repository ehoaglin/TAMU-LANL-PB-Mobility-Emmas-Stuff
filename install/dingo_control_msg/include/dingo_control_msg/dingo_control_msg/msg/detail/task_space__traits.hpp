// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dingo_control_msg:msg/TaskSpace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_control_msg/msg/task_space.hpp"


#ifndef DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__TRAITS_HPP_
#define DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dingo_control_msg/msg/detail/task_space__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace dingo_control_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const TaskSpace & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: fl_foot
  {
    if (msg.fl_foot.size() == 0) {
      out << "fl_foot: []";
    } else {
      out << "fl_foot: [";
      size_t pending_items = msg.fl_foot.size();
      for (auto item : msg.fl_foot) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: fr_foot
  {
    if (msg.fr_foot.size() == 0) {
      out << "fr_foot: []";
    } else {
      out << "fr_foot: [";
      size_t pending_items = msg.fr_foot.size();
      for (auto item : msg.fr_foot) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: rl_foot
  {
    if (msg.rl_foot.size() == 0) {
      out << "rl_foot: []";
    } else {
      out << "rl_foot: [";
      size_t pending_items = msg.rl_foot.size();
      for (auto item : msg.rl_foot) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: rr_foot
  {
    if (msg.rr_foot.size() == 0) {
      out << "rr_foot: []";
    } else {
      out << "rr_foot: [";
      size_t pending_items = msg.rr_foot.size();
      for (auto item : msg.rr_foot) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskSpace & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: fl_foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.fl_foot.size() == 0) {
      out << "fl_foot: []\n";
    } else {
      out << "fl_foot:\n";
      for (auto item : msg.fl_foot) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: fr_foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.fr_foot.size() == 0) {
      out << "fr_foot: []\n";
    } else {
      out << "fr_foot:\n";
      for (auto item : msg.fr_foot) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: rl_foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rl_foot.size() == 0) {
      out << "rl_foot: []\n";
    } else {
      out << "rl_foot:\n";
      for (auto item : msg.rl_foot) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: rr_foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rr_foot.size() == 0) {
      out << "rr_foot: []\n";
    } else {
      out << "rr_foot:\n";
      for (auto item : msg.rr_foot) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskSpace & msg, bool use_flow_style = false)
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
  const dingo_control_msg::msg::TaskSpace & msg,
  std::ostream & out, size_t indentation = 0)
{
  dingo_control_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dingo_control_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const dingo_control_msg::msg::TaskSpace & msg)
{
  return dingo_control_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dingo_control_msg::msg::TaskSpace>()
{
  return "dingo_control_msg::msg::TaskSpace";
}

template<>
inline const char * name<dingo_control_msg::msg::TaskSpace>()
{
  return "dingo_control_msg/msg/TaskSpace";
}

template<>
struct has_fixed_size<dingo_control_msg::msg::TaskSpace>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<dingo_control_msg::msg::TaskSpace>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<dingo_control_msg::msg::TaskSpace>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DINGO_CONTROL_MSG__MSG__DETAIL__TASK_SPACE__TRAITS_HPP_
