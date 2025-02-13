// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from dingo_peripheral_interfacing:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "dingo_peripheral_interfacing/msg/detail/electrical_measurements__struct.h"
#include "dingo_peripheral_interfacing/msg/detail/electrical_measurements__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool dingo_peripheral_interfacing__msg__electrical_measurements__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[81];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("dingo_peripheral_interfacing.msg._electrical_measurements.ElectricalMeasurements", full_classname_dest, 80) == 0);
  }
  dingo_peripheral_interfacing__msg__ElectricalMeasurements * ros_message = _ros_message;
  {  // battery_voltage_level
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_voltage_level");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->battery_voltage_level = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // servo_buck_voltage_level
    PyObject * field = PyObject_GetAttrString(_pymsg, "servo_buck_voltage_level");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->servo_buck_voltage_level = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * dingo_peripheral_interfacing__msg__electrical_measurements__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ElectricalMeasurements */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("dingo_peripheral_interfacing.msg._electrical_measurements");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ElectricalMeasurements");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  dingo_peripheral_interfacing__msg__ElectricalMeasurements * ros_message = (dingo_peripheral_interfacing__msg__ElectricalMeasurements *)raw_ros_message;
  {  // battery_voltage_level
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->battery_voltage_level);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_voltage_level", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // servo_buck_voltage_level
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->servo_buck_voltage_level);
    {
      int rc = PyObject_SetAttrString(_pymessage, "servo_buck_voltage_level", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
