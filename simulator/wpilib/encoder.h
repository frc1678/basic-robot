#pragma once

#include "simulator/event/event.h"
#include "simulator/event/event_manager.h"

class EncoderData : public EventData {
 public:
  EncoderData(int clicks, int channel_a, int channel_b)
      : EventData(kEventType) {
    this->clicks = clicks;
    this->channel_a = channel_a;
    this->channel_b = channel_b;
  }
  int clicks;
  int channel_a, channel_b;
  static int kEventType;
};

class Encoder {
 public:
  Encoder(int channel_a, int channel_b) {
    EventManager::GetInstance()->RegisterListener(
        EncoderData::kEventType, [=](EventData* data) {
          EncoderData* enc_data = (EncoderData*)data;
          if (enc_data->channel_a == channel_a &&
              enc_data->channel_b == channel_b) {
            this->clicks_ = enc_data->clicks;
          }
        });
    this->clicks_ = 0;
  }
  int Get() { return clicks_; }

 private:
  int clicks_;
};
