#ifndef DRIVE_CONTROLLER_H
#define DRIVE_CONTROLLER_H
#include "unitscpp/unitscpp.h"
#include "trapezoidal_motion_profile.h"
#include <WPILib.h>

class DriveController {
  Length goal_distance_;
  Units<1, -3, 1, -1> kP = 3 * V / m;
  Units<1, -2, 1, -1> kD = 1 * V * s / m;
  Length last_error_;
  TrapezoidalMotionProfile<Length> tmp;
  Timer* timer;

 public:
  DriveController();
  ~DriveController();
  Voltage Update(Length left_encoder, Length right_encoder);
  void SetDistanceGoal(Length distance);
};
#endif
