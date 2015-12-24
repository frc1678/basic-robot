#pragma once

#include "simulator/event/event_manager.h"

class SpeedControllerData : public EventData {
 public:
  SpeedControllerData(double value, int channel) : EventData(kEventType) {
    this->value = value;
    this->channel = channel;
  }
  int channel;
  double value;
  static int kEventType;
};

int SpeedControllerData::kEventType = 0xA34CD809;

class SpeedController {
 public:
  SpeedController(int channel) : channel_(channel) {}
  void Set(double value) {
    value = std::min(1.0, std::max(-1.0, value));
    EventManager::GetInstance()->QueueEvent(
        Event(new SpeedControllerData(value, channel_)));
  }

 private:
  int channel_;
};

typedef SpeedController VictorSP;
typedef SpeedController Victor;
typedef SpeedController Talon;
typedef SpeedController TalonSRX;
