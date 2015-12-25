#include "renderer.h"
#include "simulator/event/event_manager.h"
#include "simulator/model/robot_position.h"
#include "simulator/wpilib/solenoid.h"
#include "simulator/model/intake.h"

Renderer::Renderer() : window(sf::VideoMode(800, 600), "citrus-sim") {
  this->robot_x = 0;
  this->robot_y = 0;
  this->robot_theta = 0;
  EventManager::GetInstance()->RegisterListener(
      RobotPositionData::kEventType, [this](EventData* data) {
        RobotPositionData* pos_data = (RobotPositionData*)data;
        this->robot_x = (int)pos_data->x.to(in);
        this->robot_y = (int)pos_data->y.to(in);
        this->robot_theta = pos_data->theta.to(deg);
      });
  EventManager::GetInstance()->RegisterListener(
      IntakeData::kEventType, [this](EventData* data) {
        IntakeData* in_data = (IntakeData*)data;
        this->intake_ = in_data->angle;
      });
}

Renderer::~Renderer() {}

bool Renderer::Render() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) return false;
  }
  window.clear();
  robot.setSize(sf::Vector2f(30, 20));
  robot.setOrigin(15, 10);
  robot.setPosition(robot_x + 400, robot_y + 300);
  robot.setRotation(robot_theta);
  window.draw(robot);

  intake.setSize(sf::Vector2f(10, 50));
  intake.setOrigin(5, 45);
  intake.setRotation(intake_.to(deg));
  intake.setPosition(75, 75);
  window.draw(intake);
  window.display();
  return true;
}
