#include "solenoid.h"

Solenoid::Solenoid(int channel) {
  this->open_ = false;
  this->channel_ = channel;
}

void Solenoid::Set(bool open) {
  if (open != open_) {
    EventManager::GetInstance()->QueueEvent(Event(new SolenoidData(open, channel_)));
  }
  open_ = open;
}
