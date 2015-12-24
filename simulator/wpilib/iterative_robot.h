#pragma once

class IterativeRobot {
 public:
  IterativeRobot() {}
  ~IterativeRobot() {}
  virtual void RobotInit() {}
  virtual void DisabledInit() {}
  virtual void DisabledPeriodic() {}
  virtual void AutonomousInit() {}
  virtual void AutonomousPeriodic() {}
  virtual void TeleopInit() {}
  virtual void TeleopPeriodic() {}
};
