#include "dashboard.h"
#include <iostream>
#include <SFML/Window.hpp>
#include "simulator/state_change.h"
#include "simulator/event/event_manager.h"

Dashboard::Dashboard() : window_(sf::VideoMode(400, 400), "dashboard") {
  font.loadFromFile("simulator/arial.ttf");
}

Dashboard::~Dashboard() {
  window_.close();
}

bool Dashboard::Render() {
  // Update the buttons
  sf::Event event;
  while (window_.pollEvent(event)) {
    if (event.type == sf::Event::Closed) return false;
  }
  if (enabled_ && sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
    enabled_ = false;
    EventManager::GetInstance()->QueueEvent(Event(new StateChangeData(Disabled)));
  }
  if (!enabled_ && sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
    enabled_ = true;
    if (auto_)
      EventManager::GetInstance()->QueueEvent(Event(new StateChangeData(Autonomous)));
    else
      EventManager::GetInstance()->QueueEvent(Event(new StateChangeData(Teleop)));
  }
  if (!enabled_ && auto_ && sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
    auto_ = false;
  }
  if (!enabled_ && !auto_ && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    auto_ = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return false;

  // Render everything
  sf::RectangleShape enable;
  enable.setFillColor(enabled_ ? sf::Color(0, 255, 0) : sf::Color(255, 0, 0));
  enable.setPosition(enable_position_);
  enable.setSize(enable_size_);

  sf::Text mode(auto_ ? "Auto" : "Teleop", font);
  mode.setColor(sf::Color(255, 255, 255));
  mode.setPosition(teleop_position_);

  window_.clear();
  window_.draw(enable);
  window_.draw(mode);
  window_.display();
  return true;
}
