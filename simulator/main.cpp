#include "main.h"

#ifdef __STANDALONE__
class TestRobotClass {
  VictorSP *left, *right;
 public:
  TestRobotClass() {
    left = new VictorSP(2);
    right = new VictorSP(1);
  }
  ~TestRobotClass() {}
  void RobotInit() {}
  void DisabledInit() {}
  void DisabledPeriodic() {}
  void AutonomousInit() {}
  void AutonomousPeriodic() {}
  void TeleopInit() {}
  void TeleopPeriodic() { left->Set(1); right->Set(-1);}
};

START_ROBOT_CLASS(TestRobotClass);
#endif
