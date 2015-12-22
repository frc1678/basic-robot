#include "drive_controller.h"
#include <iostream>
#include <WPILib.h>

DriveController::DriveController()
    : tmp(0 * m, maxHighRobotSpeed, 2 * m / s / s) {
  timer = new Timer();
}

DriveController::~DriveController() { delete timer; }

Voltage DriveController::Update(Length left_encoder, Length right_encoder) {
  Units<1, -2, 1, -1> Kv = 12 * V / maxHighRobotSpeed;
  return tmp.CalculateSpeed(timer->Get() * s) * Kv;
}

void DriveController::SetDistanceGoal(Length distance) {
  tmp = TrapezoidalMotionProfile<Length>(distance, maxHighRobotSpeed,
                                         2 * m / s / s);
  timer->Reset();
  timer->Start();
}
