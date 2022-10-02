/**
 * @file pid.hpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Class Pid declaration
 * @version 0.1
 * @date 2022-10-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

#ifndef PID_IMP_INCLUDE_PID_HPP_
#define PID_IMP_INCLUDE_PID_HPP_

class PID {
 private:
  double K_d;   // Diffrential Const
  double K_i;   // Integral Const
  double K_p;   // Propotional const
  double _max;  // Max Output
  double _min;  // Min Output
  double dt;    // diffrential change in time
  double integral{};
  double pre_error{};
  // constructor

 public:
  PID(double Kp, double Kd, double Ki, double max_out, double min_out,
      double t);  // Constructor with parameters

  /**
   * @brief
   * @param val -actual velocity
   * @param setpoint -target setpoint
   */

  double cal_pid(double val, double setpoint);
};

#endif  // PID_IMP_INCLUDE_PID_HPP_
