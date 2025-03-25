// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dingo_peripheral_interfacing_msg:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_peripheral_interfacing_msg/msg/electrical_measurements.hpp"


#ifndef DINGO_PERIPHERAL_INTERFACING_MSG__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__BUILDER_HPP_
#define DINGO_PERIPHERAL_INTERFACING_MSG__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dingo_peripheral_interfacing_msg/msg/detail/electrical_measurements__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dingo_peripheral_interfacing_msg
{

namespace msg
{

namespace builder
{

class Init_ElectricalMeasurements_servo_buck_voltage_level
{
public:
  explicit Init_ElectricalMeasurements_servo_buck_voltage_level(::dingo_peripheral_interfacing_msg::msg::ElectricalMeasurements & msg)
  : msg_(msg)
  {}
  ::dingo_peripheral_interfacing_msg::msg::ElectricalMeasurements servo_buck_voltage_level(::dingo_peripheral_interfacing_msg::msg::ElectricalMeasurements::_servo_buck_voltage_level_type arg)
  {
    msg_.servo_buck_voltage_level = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dingo_peripheral_interfacing_msg::msg::ElectricalMeasurements msg_;
};

class Init_ElectricalMeasurements_battery_voltage_level
{
public:
  Init_ElectricalMeasurements_battery_voltage_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ElectricalMeasurements_servo_buck_voltage_level battery_voltage_level(::dingo_peripheral_interfacing_msg::msg::ElectricalMeasurements::_battery_voltage_level_type arg)
  {
    msg_.battery_voltage_level = std::move(arg);
    return Init_ElectricalMeasurements_servo_buck_voltage_level(msg_);
  }

private:
  ::dingo_peripheral_interfacing_msg::msg::ElectricalMeasurements msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dingo_peripheral_interfacing_msg::msg::ElectricalMeasurements>()
{
  return dingo_peripheral_interfacing_msg::msg::builder::Init_ElectricalMeasurements_battery_voltage_level();
}

}  // namespace dingo_peripheral_interfacing_msg

#endif  // DINGO_PERIPHERAL_INTERFACING_MSG__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__BUILDER_HPP_
