#include "robot_drive.h"

RobotDrive::RobotDrive(int left, int right) {
  left_a_ = new SpeedController(left);
  right_a_ = new SpeedController(right);
  left_b_ = nullptr;
  right_b_ = nullptr;
}

RobotDrive::RobotDrive(int front_left, int rear_left, int front_right, int rear_right) {
  left_a_ = new SpeedController(front_left);
  right_a_ = new SpeedController(front_right);
  left_b_ = new SpeedController(rear_left);
  right_b_ = new SpeedController(rear_right);
}

RobotDrive::RobotDrive(SpeedController* left, SpeedController* right) {
  left_a_ = left;
  right_a_ = right;
  left_b_ = nullptr;
  right_b_ = nullptr;
}

RobotDrive::RobotDrive(SpeedController* front_left, SpeedController* rear_left, SpeedController* front_right, SpeedController* rear_right) {
  left_a_ = front_left;
  right_a_ = front_right;
  left_b_ = rear_left;
  right_b_ = rear_right;
}

void RobotDrive::TankDrive(double power_left, double power_right) {
  if (right_a_ != nullptr) right_a_->Set(power_right);
  if (right_b_ != nullptr) right_b_->Set(power_right);
  if (left_a_ != nullptr) left_a_->Set(power_left);
  if (left_b_ != nullptr) left_b_->Set(power_left);
}
