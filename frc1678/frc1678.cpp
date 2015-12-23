#include <WPILib.h>
#include "muan/multithreading/updateable.h"
#include "robot_subsystems.h"
#include "frc1678/auto/auto.h"
#include <memory>

class CitrusRobot : public IterativeRobot {
 public:
  CitrusRobot() {
    j1_ = new Joystick(0);
    j2_ = new Joystick(1);
    auto_ =
        std::unique_ptr<AutoStateMachine>(new AutoStateMachine(subsystems_));
    subsystems_.drive.Start();
  }
  void AutonomousInit() { auto_->Start(); }
  void AutonomousPeriodic() { auto_->Update(); }
  void RobotInit() {}
  void TeleopInit() {}
  void TeleopPeriodic() {
    subsystems_.drive.DriveTank(j1_->GetY() * 12 * ft / s,
                                j2_->GetY() * 12 * ft / s);
  }
  ~CitrusRobot() { subsystems_.drive.Join(); }

 private:
  Joystick *j1_, *j2_;
  std::unique_ptr<AutoStateMachine> auto_;
  RobotSubsystems subsystems_;
};

START_ROBOT_CLASS(CitrusRobot);
