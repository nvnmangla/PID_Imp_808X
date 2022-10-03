/**
 * @file main.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @author Smit Dumore (smitd@umd.edu)
 * @brief Driver for PID 
 * @version 0.1
 * @date 2022-10-01
 * @copyright Copyright (c) 2022
 *
 */

#include <pid.hpp>

int main() {
  PID mypid(0.01, 0.1, 0.5, 100, -100, 0.1);
  double init_vel = 10;  // initial velocity value
  for (int i{}; i < 10; i++) {
    auto out = mypid.cal_pid(init_vel, 0);  // running PID
    init_vel += out;
  }
  return 0;
}
