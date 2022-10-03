/**
 * @file test.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Testing 
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <gtest/gtest.h>
#include "pid.hpp"


/**
 * @brief Construct a new TEST case output1
 * 
 */
TEST(PID, output) {
  PID pid(0.01, 0.1, 0.5, 100, -100, 0.1);
  EXPECT_EQ(-21.2, pid.cal_pid(20,0));
}

/**
 * @brief Construct a new TEST case output2
 * 
 */
TEST(PID, output2) {
  PID pid(0.01, 0.1, 0.5, 100, -100, 0.1);
  EXPECT_EQ(-31.2, pid.cal_pid(30,0));
}
