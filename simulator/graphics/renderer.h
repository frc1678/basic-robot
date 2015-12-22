#pragma once

#include <SFML/Graphics.hpp>

class Renderer {
 public:
  Renderer();
  virtual ~Renderer();
  bool Render();

 private:
  int robot_x, robot_y;
  double robot_theta;
  sf::RenderWindow window;
  sf::RectangleShape robot;
};
