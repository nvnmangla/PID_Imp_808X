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

#include <pid.hpp>

double PID::cal_pid(double init_vel, double setpoint_vel) {
  double error = setpoint_vel - init_vel;

  double p_out = PID::K_p * error;

  if (dt == 0) {
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
  }

  double derivative = (error - PID::pre_error) / PID::dt;

  double d_out = PID::K_d * derivative;

  PID::integral += error * (PID::dt);

  double i_out = PID::K_i * PID::integral;

  double output = p_out + d_out + i_out;

  PID::pre_error = error;

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
