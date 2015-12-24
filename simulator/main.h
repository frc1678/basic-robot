#pragma once

#include "event/event_manager.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "wpilib/WPILib.h"
#include "simulator/model/drive_plant.h"
#include "simulator/graphics/renderer.h"
#include "dashboard/dashboard.h"
#include "state_change.h"

class StringEventData : public EventData {
 public:
  StringEventData(std::string text) : EventData(0) { this->text = text; }
  virtual ~StringEventData() {}
  std::string text;
};

template <typename RobotClass>
int run() {
  Renderer r;
  Dashboard dash;
  RobotClass code;

  DrivePlant drive_plant(2, 1, 10, 11, 12, 13);

  int current = Disabled;
  EventManager::GetInstance()->RegisterListener(StateChangeData::kEventType, [&] (EventData* evt) {
    StateChangeData* sc_data = (StateChangeData*)evt;
    current = sc_data->state;
    if (current == States::Autonomous) {
      code.AutonomousInit();
    }
    else if (current == States::Teleop) {
      code.TeleopInit();
    }
    else if (current == States::Disabled) {
      code.DisabledInit();
    }
  });

  code.RobotInit();
  code.DisabledInit();
  while (r.Render() && dash.Render()) {
    if (current == States::Autonomous) {
      code.AutonomousPeriodic();
    }
    else if (current == States::Teleop) {
      code.TeleopPeriodic();
    }
    else if (current == States::Disabled) {
      code.DisabledPeriodic();
    }

    drive_plant.Update(.02*s);
    EventManager::GetInstance()->Update();
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
  }
}

#define START_ROBOT_CLASS(RobotClass) int main() { run<RobotClass>(); }
