/**
 * @file pid.cpp
 * @author Naveen Mangla(nmangla@umd.edu)
 * @author Dhanush Babu allam (dallam@umd.edu)
 * @author Smit Dumore (smitd@umd.edu)
 * @brief definiation of function cal_pid
 * @version 0.2
 * @date 2022-10-01
 *
 * @copyright Copyright (c) 2022
 *
 */

/// including headers
#include <pid.hpp>

double PID::cal_pid(double init_vel, double setpoint_vel) {
  /// error calculated by subtracting setpoint velocity from initial velocity
  double error = setpoint_vel - init_vel;

  /// proportional correction
  double p_out = PID::K_p * error;

  /// throwing an error if values of dt is 0
  if (dt == 0) {
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
  }

  double derivative = (error - PID::pre_error) / PID::dt;

  /// derivative correction
  double d_out = PID::K_d * derivative;

  PID::integral += error * (PID::dt);

  /// integral correction
  double i_out = PID::K_i * PID::integral;

  /// output is the sum of P, D and I terms
  double output = p_out + d_out + i_out;

  /// updating pre_error as current error
  PID::pre_error = error;

  /// checking the output to stay in actuator limits
  if (output > PID::_max) {
    output = PID::_max;
  } else if (output < PID::_min) {
    output = PID::_min;
  }

  std::cout << "PID is running " << output << "\n";

  return output;
}

PID::PID(double Kp, double Kd, double Ki, double max_out, double min_out,
         double t) {  // Constructor with parameters
  K_d = Kd;
  K_i = Ki;
  K_p = Kp;
  _max = max_out;
  _min = min_out;
  dt = t;
}

double PID::get_dt() {
  return this->dt;
}
