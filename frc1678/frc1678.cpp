#include __WPILIB__

class CitrusRobot {
  VictorSP *left, *right;
  Joystick joy;

 public:
  CitrusRobot() : joy(0) {
    right = new VictorSP(2);
    left = new VictorSP(1);
  }
  void RobotInit() {}
  void AutonomousInit() {}
  void AutonomousPeriodic() {}
  void DisabledInit() {}
  void DisabledPeriodic() {}
  void TeleopInit() {}
  void TeleopPeriodic() {
    right->Set(joy.GetY());
    left->Set(joy.GetY());
  }
  ~CitrusRobot() {}
};

START_ROBOT_CLASS(CitrusRobot);
