#include "drive_plant.h"

DrivePlant::DrivePlant() {
  Units<2, -2, 1, -1> K_t = 18.803 * V * s;
  Units<2, -2, 1, -1> K_v = 18.803 * V * s;
  Resistance R = .0902 / 2 * ohm;
  Length W = 14 * in;
  Length r_w = 2 * in;
  Units<2, 0, 1, 0> J = 10 * kg * m * m;
  Units<0, 0, 1, 0> mass = 120 * lb_mass;
  double G_h = 4;
  double G_l = 9;
  double kF_rotation =
      -((K_t * K_v * W * W) / (J * G_h * R * r_w * r_w)).to(1 / s);
  double kF_velocity =
      -((2 * K_t * K_v) / (G_h * R * mass * r_w * r_w)).to(1 / s);
  double kM_rotation = ((K_t * W) / (J * R * r_w)).to(1 / V / s / s);
  double kM_velocity = ((K_t) / (R * mass * r_w)).to(m / V / s / s);
  A << 0.0, 1.0, 0.0, 0.0, 0.0, -kF_rotation, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      0.0, 0.0, -kF_velocity;
  B << 0.0, 0.0, kM_rotation, -kM_rotation, 0.0, 0.0, kM_velocity, kM_velocity;
}

DrivePlant::~DrivePlant() {}

void DrivePlant::Update(Voltage left, Voltage right) {
  Eigen::Vector2d u;
  u << right.to(V), left.to(V);
  x_ += (A * x_ + B * u) * .05;
}

Angle DrivePlant::Angle() { return x_(0); }

AngularVelocity DrivePlant::AngularVelocity() { return x_(1); }

Length DrivePlant::Distance() { return x_(2); }

Velocity DrivePlant::ForwardVelocity() { return x_(3); }
