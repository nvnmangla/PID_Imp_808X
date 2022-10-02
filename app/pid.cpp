
/**
 * @file pid.cpp
 * @author Naveen Mangla(nmangla@umd.edu)
 * @brief definiation of function cal_pid
 * @version 0.1
 * @date 2022-10-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <pid.hpp>

double PID::cal_pid(double val, double setpoint) { return 2.000; }

PID::PID(double Kp, double Kd, double Ki, double max_out, double min_out,
      double t) {  // Constructor with parameters
    K_d = Kd;
    K_i = Ki;
    K_p = Kp;
    _max = max_out;
    _min = min_out;
    dt = t;
}
