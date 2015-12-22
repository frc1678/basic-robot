#include "drive_subsystem.h"

DriveSubsystem::DriveSubsystem() : Updateable(100 * hz) {
  drivetrain_ = new RobotDrive(2, 1);
  enc_left_ = new Encoder(10, 11);
  enc_right_ = new Encoder(12, 13);
  current_mode_ = VELOCITY;
}

DriveSubsystem::~DriveSubsystem() {}

void DriveSubsystem::Update(Time dt) {
  Length current_dist = enc_left_->Get() * click;
  if (current_mode_ == DISTANCE) {
    Voltage v =
        controller_.Update(enc_left_->Get() * click, enc_right_->Get() * click);
    drivetrain_->TankDrive(v.to(12 * V), v.to(12 * V));
  } else if (current_mode_ == VELOCITY) {
    Units<1, -2, 1, -1> K_v = 12 * V / maxHighRobotSpeed;
    drivetrain_->TankDrive((K_v * target_velocity_right_).to(12 * V),
                           (K_v * target_velocity_left_).to(12 * V));
  }
}

void DriveSubsystem::DriveTank(Velocity right, Velocity left) {
  target_velocity_right_ = right;
  target_velocity_left_ = left;
}

void DriveSubsystem::DriveDistance(Length dist) {
  target_dist_ = dist;
  current_mode_ = DISTANCE;
}

bool DriveSubsystem::IsDone() { return current_mode_ == VELOCITY; }
