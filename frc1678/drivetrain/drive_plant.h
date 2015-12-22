#include "unitscpp/unitscpp.h"
#include "Eigen/Core"

class DrivePlant {
 public:
  DrivePlant();
  ~DrivePlant();
  void Update(Voltage left, Voltage right);
  Angle Angle();
  AngularVelocity AngularVelocity();
  Length Distance();
  Velocity ForwardVelocity();

 private:
  Eigen::Matrix<double, 4, 4> A;
  Eigen::Matrix<double, 4, 2> B;
  Eigen::Matrix<double, 2, 4> C;
  Eigen::Vector4d x_;
};
