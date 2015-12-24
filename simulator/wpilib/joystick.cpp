#include "joystick.h"
#include <iostream>

Joystick::Joystick(int id) : id_(id) {
}

double Joystick::GetX() {
  return sf::Joystick::getAxisPosition(id_, sf::Joystick::X) / 100.0;
}

double Joystick::GetY() {
  return sf::Joystick::getAxisPosition(id_, sf::Joystick::Y) / 100.0;
}

double Joystick::GetZ() {
  return sf::Joystick::getAxisPosition(id_, sf::Joystick::Z) / 100.0;
}

bool Joystick::GetTrigger() {
  return sf::Joystick::isButtonPressed(id_, 0);
}

double Joystick::GetRawAxis(int axis) {
  sf::Joystick::Axis axis_int = sf::Joystick::Axis::PovY;
  if (axis == 0) axis_int = sf::Joystick::X;
  else if (axis == 1) axis_int = sf::Joystick::Y;
  else if (axis == 2) axis_int = sf::Joystick::Z;
  return sf::Joystick::getAxisPosition(id_, axis_int) / 100.0;
}

bool Joystick::GetRawButton(int button) {
  return sf::Joystick::isButtonPressed(id_, button);
}
