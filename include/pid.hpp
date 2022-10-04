/**
 * @file pid.hpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @author Smit Dumore (smitd@umd.edu)
 * @brief Class Pid declaration
 * @version 0.2
 * @date 2022-10-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <stdexcept>

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
   * @param init_vel -actual velocity
   * @param setpoint_vel -target setpoint
   */
  double cal_pid(double init_vel, double setpoint_vel);

  /**
   * @brief
   * @return value of dt
   */
  double get_dt();
};

#endif  // PID_IMP_INCLUDE_PID_HPP_
