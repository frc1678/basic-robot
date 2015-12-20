#include "drive_subsystem.h"

DriveSubsystem::DriveSubsystem() : Updateable(100 * hz) {
  _drivetrain = new RobotDrive(2, 1);
  enc_left = new Encoder(10, 11);
  enc_right = new Encoder(12, 13);
}

DriveSubsystem::~DriveSubsystem() {}

void DriveSubsystem::update(Time dt) {
  Length current_dist = enc_left->Get() * click;
  // if (current_dist < target_dist) {
  //   _drivetrain->TankDrive(1.0, 1.0);
  // }
}

void DriveSubsystem::drive_tank(Velocity right, Velocity left) {
  Units<1, -2, 1, -1> K_v = 12 * V / maxHighRobotSpeed;
  _drivetrain->TankDrive((K_v * right).to(12 * V), (K_v * left).to(12 * V));
}

void DriveSubsystem::drive_distance(Length dist) { target_dist = dist; }
