#include "event/event_manager.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "wpilib/WPILib.h"
#include "simulator/model/drive_plant.h"
#include "simulator/graphics/renderer.h"

class StringEventData : public EventData {
 public:
  StringEventData(std::string text) : EventData(0) { this->text = text; }
  virtual ~StringEventData() {}
  std::string text;
};

template <typename RobotClass>
int run() {
  /*em.RegisterListener(0, [](EventData* data) {
    StringEventData* d2 = (StringEventData*) data;
    std::cout << d2->text << std::endl;
  });*/
  Renderer r;
  RobotClass code;
  Encoder enc(1, 2);
  DrivePlant drive_plant(2, 1, 10, 11, 12, 13);
  // em.QueueEvent(Event(new StringEventData("test")));
  EventManager::GetInstance()->QueueEvent(Event(new EncoderData(42, 1, 2)));
  SpeedController left(2);
  SpeedController right(1);
  Encoder left_enc(10, 11);
  Encoder right_enc(12, 13);
  EventManager::GetInstance()->RegisterListener(
      RobotPositionData::kEventType, [](EventData* data) {
        RobotPositionData* pos_data = (RobotPositionData*)data;
        std::cout << pos_data->x << ", " << pos_data->y << ", "
                  << pos_data->theta << std::endl;
      });

  double t = 0;
  code.TeleopInit();
  while (r.Render()) {
    code.TeleopPeriodic();
    t += .01;
    left.Set(.5);
    right.Set(1);
    drive_plant.Update(.05);
    EventManager::GetInstance()->Update();
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
}
