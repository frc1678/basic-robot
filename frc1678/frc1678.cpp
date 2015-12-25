#include __WPILIB__
#include "auto.h"

class CitrusRobot : public IterativeRobot {
  RobotDrive* drive;
  Solenoid* intake;
  Joystick joy;
  AutoStateMachine* auto_;

 public:
  CitrusRobot() : joy(0) {
    drive = new RobotDrive(2, 1);
    intake = new Solenoid(0);
    auto_ = new AutoStateMachine(drive);
  }
  void RobotInit() {}
  void AutonomousInit() {
    auto_->Start();
  }
  void AutonomousPeriodic() {
    auto_->Update();
  }
  void DisabledInit() {}
  void DisabledPeriodic() {}
  void TeleopInit() {}
  void TeleopPeriodic() {
    drive->TankDrive(-joy.GetY(), joy.GetY());
    if (joy.GetTrigger()) intake->Set(true);
    else intake->Set(false);
  }
  ~CitrusRobot() {}
};
START_ROBOT_CLASS(CitrusRobot);
