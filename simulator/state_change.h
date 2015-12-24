#pragma once
#include "event/event.h"

enum States {
  Disabled,
  Autonomous,
  Teleop
};

class StateChangeData : public EventData {
 public:
  StateChangeData(States state) : EventData(kEventType), state(state) {}
  States state;
  static int kEventType;
};
