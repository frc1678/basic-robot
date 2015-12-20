#include "drive_subsystem.h"

DriveSubsystem::DriveSubsystem() : Updateable(100 * hz) {
  _drivetrain = new RobotDrive(2, 1);
  enc_left = new Encoder(10, 11);
  enc_right = new Encoder(12, 13);
  current_mode = VELOCITY;
}

DriveSubsystem::~DriveSubsystem() {}

void DriveSubsystem::update(Time dt) {
  Length current_dist = enc_left->Get() * click;
  if (current_mode == DISTANCE) {
    if (current_dist < target_dist) {
      _drivetrain->TankDrive(1.0, 1.0);
    } else {
      current_mode = VELOCITY;
    }
  } else if (current_mode == VELOCITY) {
    Units<1, -2, 1, -1> K_v = 12 * V / maxHighRobotSpeed;
    _drivetrain->TankDrive((K_v * target_velocity_right).to(12 * V),
                           (K_v * target_velocity_left).to(12 * V));
  }
}

void DriveSubsystem::drive_tank(Velocity right, Velocity left) {
  target_velocity_right = right;
  target_velocity_left = left;
}

void DriveSubsystem::drive_distance(Length dist) {
  target_dist = dist;
  current_mode = DISTANCE;
}

bool DriveSubsystem::is_done() { return current_mode == VELOCITY; }
