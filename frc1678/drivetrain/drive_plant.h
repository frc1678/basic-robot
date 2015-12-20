#include "unitscpp/unitscpp.h"
#include "Eigen/Core"

class DrivePlant {
 public:
  DrivePlant();
  ~DrivePlant();
  void update(Voltage left, Voltage right);
  Angle angle();
  AngularVelocity angular_velocity();
  Length distance();
  Velocity forward_velocity();

 private:
  Eigen::Matrix<double, 4, 4> A;
  Eigen::Matrix<double, 4, 2> B;
  Eigen::Matrix<double, 2, 4> C;
  Eigen::Vector4d _x;
};
