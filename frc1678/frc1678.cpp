#include <WPILib.h>
#include "muan/multithreading/updateable.h"
#include "frc1678/drivetrain/drive_subsystem.h"

class CitrusRobot : public IterativeRobot {
 public:
  CitrusRobot() {
    drive.start();
    j1 = new Joystick(0);
    j2 = new Joystick(1);
  }
  void RobotInit() {}
  void TeleopInit() {}
  void TeleopPeriodic() {
    drive.drive_tank(j1->GetY() * 12 * ft / s, j2->GetY() * 12 * ft / s);
  }
  ~CitrusRobot() { drive.stop(); }

  DriveSubsystem drive;

 private:
  Joystick* j1, *j2;
};

START_ROBOT_CLASS(CitrusRobot);
