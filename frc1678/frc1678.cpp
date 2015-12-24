#include __WPILIB__

class CitrusRobot {
  RobotDrive* drive;
  Joystick joy;

 public:
  CitrusRobot() : joy(0) {
    drive = new RobotDrive(2, 1);
  }
  void RobotInit() {}
  void AutonomousInit() {
    SmartDashboard::PutNumber("Auto", 1.0);
  }
  void AutonomousPeriodic() {}
  void DisabledInit() {}
  void DisabledPeriodic() {}
  void TeleopInit() {}
  void TeleopPeriodic() {
    drive->TankDrive(-joy.GetY(), joy.GetY());
  }
  ~CitrusRobot() {}
};

START_ROBOT_CLASS(CitrusRobot);
