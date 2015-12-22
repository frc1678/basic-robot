#pragma once

#include "simulator/event/event.h"
#include "unitscpp/unitscpp.h"

class RobotPositionData : public EventData {
 public:
  RobotPositionData(Length x, Length y, Angle theta)
      : EventData(kEventType), x(x), y(y), theta(theta) {}
  Length x, y;
  Angle theta;
  static int kEventType;
};
