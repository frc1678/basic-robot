#include <WPILib.h>
#include "muan/multithreading/updateable.h"
#include "robot_subsystems.h"
#include "frc1678/auto/auto.h"
#include <memory>

class CitrusRobot : public IterativeRobot {
 public:
  CitrusRobot() {
    j1 = new Joystick(0);
    j2 = new Joystick(1);
    _auto = std::unique_ptr<AutoStateMachine>(new AutoStateMachine(subsystems));
    subsystems.drive.start();
  }
  void AutonomousInit() { _auto->start(); }
  void AutonomousPeriodic() { _auto->update(); }
  void RobotInit() {}
  void TeleopInit() {}
  void TeleopPeriodic() {
    subsystems.drive.drive_tank(j1->GetY() * 12 * ft / s,
                                j2->GetY() * 12 * ft / s);
  }
  ~CitrusRobot() { subsystems.drive.stop(); }

  RobotSubsystems subsystems;

 private:
  Joystick *j1, *j2;
  std::unique_ptr<AutoStateMachine> _auto;
};

START_ROBOT_CLASS(CitrusRobot);
