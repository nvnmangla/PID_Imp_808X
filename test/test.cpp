#include <gtest/gtest.h>
#include "pid.hpp"


// Test Case 1
TEST(PID, output) {
  PID pid(0.01, 0.1, 0.5, 100, -100, 0.1);
  EXPECT_EQ(2.5, pid.cal_pid(20,0));
}

// Test Case 2
TEST(PID, output) {
  PID pid(0.01, 0.1, 0.5, 100, -100, 0.1);
  EXPECT_EQ(2.5, pid.cal_pid(30,0));
}
