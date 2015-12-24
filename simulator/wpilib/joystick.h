#pragma once

#include <SFML/Window.hpp>

class Joystick {
 public:
  Joystick(int id);
  double GetX();
  double GetY();
  double GetZ();
  bool GetTrigger();
  double GetRawAxis(int axis);
  bool GetRawButton(int button);
 private:
  int id_;
};
