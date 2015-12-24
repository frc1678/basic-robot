#pragma once

#include "speed_controller.h"

class RobotDrive {
 public:
  RobotDrive(int left, int right);
  RobotDrive(int front_left, int rear_left, int front_right, int rear_right);

  RobotDrive(SpeedController* left, SpeedController* right);
  RobotDrive(SpeedController* front_left, SpeedController* rear_left, SpeedController* front_right, SpeedController* rear_right);

  void TankDrive(double power_left, double power_right);
 private:
  SpeedController *right_a_, *right_b_;
  SpeedController *left_a_, *left_b_;
};
