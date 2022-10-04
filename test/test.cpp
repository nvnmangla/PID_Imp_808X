/**
 * @file test.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @author Smit Dumore (smitd@umd.edu)
 * @brief Testing 
 * @version 0.2
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <gtest/gtest.h>
#include "../include/pid.hpp"


/**
 * @brief Construct a new TEST case output1 to check 
 *        correctness of PID calculations
 */
TEST(PID, output) {
  PID pid(0.01, 0.1, 0.5, 100, -100, 0.1);
  EXPECT_EQ(-21.2, pid.cal_pid(20, 0));
}

/**
 * @brief Construct a new TEST case output2 to check 
 *        correctness of PID calculations
 */
TEST(PID, output2) {
  PID pid(0.01, 0.1, 0.5, 100, -100, 0.1);
  EXPECT_EQ(-31.8, pid.cal_pid(30, 0));
}

/**
 * @brief Construct a new TEST to test max positive actuator limit
 * 
 */
TEST(PID, output3) {
  PID pid(0.01, 0.1, 0.5, 100, -100, 0.1);
  EXPECT_GE(100, pid.cal_pid(30, 0));
}

/**
 * @brief Construct a new TEST to test max negative actuator limit
 * 
 */
TEST(PID, output4) {
  PID pid(0.01, 0.1, 0.5, 100, -100, 0.1);
  EXPECT_LE(-100, pid.cal_pid(30, 0));
}

/**
 * @brief Construct a new TEST to catch runtime error while 
 *        attempting to divide by zero
 */
TEST(PID, output5) {
  PID pid(0.01, 0.1, 0.5, 100, -100, 0.0);
  EXPECT_THROW(pid.cal_pid(30, 0), std::runtime_error);
}

