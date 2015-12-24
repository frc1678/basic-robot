#include "simulator/event/event_manager.h"
#include "simulator/event/event.h"
#include "simulator/wpilib/encoder.h"
#include "simulator/wpilib/speed_controller.h"
#include "Eigen/Core"
#include "robot_position.h"
#include "unitscpp/unitscpp.h"
#include <iostream>

class DrivePlant {
 public:
  DrivePlant(int channel_left, int channel_right, int encoder_left_a,
             int encoder_left_b, int encoder_right_a, int encoder_right_b) {
    EventManager::GetInstance()->RegisterListener(
        SpeedControllerData::kEventType, [=](EventData* data) {
          SpeedControllerData* sc_data = (SpeedControllerData*)data;
          if (sc_data->channel == channel_left) {
            power_left_ = sc_data->value;
          }
          if (sc_data->channel == channel_right) {
            power_right_ = sc_data->value;
          }
        });

    a_ << 0.0, 1.0, 0.0, 0.0,
          0.0, -1.0, 0.0, 0.0,
          0.0, 0.0, 0.0, 1.0,
          0.0, 0.0, 0.0, -1.0;
    b_ << 0.0, 0.0,
          1.0, -1.0,
          0.0, 0.0,
          2.0, 2.0;
    c_ << 1.0, 0.0, 1.0, 0.0, -1.0, 0.0, 1.0, 0.0;
    state_ << 0.0, 0.0, 0.0, 0.0;
    encoder_right_a_ = encoder_right_a;
    encoder_left_a_ = encoder_left_a;
    encoder_right_b_ = encoder_right_b;
    encoder_left_b_ = encoder_left_b;
  }
  void Update(Time dt) {
    Eigen::Vector2d u;
    u << power_right_, power_left_;
    state_ += (a_ * state_ + b_ * u) * dt.to(s);
    Eigen::Vector2d y = c_ * state_;
    EventManager::GetInstance()->QueueEvent(
        Event(new EncoderData(y(0), encoder_right_a_, encoder_right_b_)));
    EventManager::GetInstance()->QueueEvent(
        Event(new EncoderData(y(1), encoder_left_a_, encoder_left_b_)));

    position_x += std::cos(state_(0)) * state_(3) * dt.to(s) * m;
    position_y += std::sin(state_(0)) * state_(3) * dt.to(s) * m;
    EventManager::GetInstance()->QueueEvent(
        Event(new RobotPositionData(position_x, position_y, state_(0) * rad)));
    power_left_ = 0;
    power_right_ = 0;
  }

 private:
  int encoder_right_a_, encoder_left_a_, encoder_right_b_, encoder_left_b_;
  double power_left_ = 0, power_right_ = 0;
  Length position_x = 0*m, position_y = 0*m;
  Eigen::Vector4d state_;
  Eigen::Matrix<double, 4, 4> a_;
  Eigen::Matrix<double, 4, 2> b_;
  Eigen::Matrix<double, 2, 4> c_;
};
