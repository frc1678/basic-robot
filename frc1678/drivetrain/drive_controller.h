#ifndef DRIVE_CONTROLLER_H
#define DRIVE_CONTROLLER_H
#include "unitscpp/unitscpp.h"

class DriveController {
  Length goal_distance;
  Units<1, -3, 1, -1> kP = 3 * V / m;
  Units<1, -2, 1, -1> kD = 1 * V * s / m;
  Length last_error;

 public:
  DriveController();
  ~DriveController();
  Voltage update(Length left_encoder, Length right_encoder);
  void set_distance_goal(Length distance);
};
#endif
