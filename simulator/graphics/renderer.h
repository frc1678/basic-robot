#pragma once

#include <SFML/Graphics.hpp>
#include "unitscpp/unitscpp.h"

class Renderer {
 public:
  Renderer();
  virtual ~Renderer();
  bool Render();

 private:
  int robot_x, robot_y;
  double robot_theta;
  Angle intake_ = 0*deg;
  sf::RenderWindow window;
  sf::RectangleShape robot;
  sf::RectangleShape intake;
};
