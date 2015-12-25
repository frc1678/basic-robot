#pragma once

#include "simulator/event/event.h"
#include "simulator/event/event_manager.h"

class SolenoidData : public EventData {
 public:
  SolenoidData(bool open, int channel)
      : EventData(kEventType), channel(channel) {
    this->open = open;
  }
  bool open;
  int channel;
  static int kEventType;
};

class Solenoid {
 public:
  Solenoid(int channel);
  void Set(bool open);

 private:
  bool open_;
  int channel_;
};
