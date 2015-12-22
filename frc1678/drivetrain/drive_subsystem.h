#ifndef FRC1678_DRIVE_DRIVESUBSYSTEM_H
#define FRC1678_DRIVE_DRIVESUBSYSTEM_H

#include "muan/multithreading/updateable.h"
#include <WPILib.h>
#include "drive_controller.h"

class DriveSubsystem : public Updateable {
 public:
  DriveSubsystem();
  ~DriveSubsystem();
  virtual void Update(Time dt) override;
  void DriveDistance(Length dist);
  void DriveTank(Velocity right, Velocity left);
  bool IsDone();

 private:
  enum Mode { VELOCITY, DISTANCE };
  Mode current_mode_;
  RobotDrive* drivetrain_;
  DriveController controller_;
  Length target_dist_;
  Velocity target_velocity_left_, target_velocity_right_;
  Encoder *enc_left_, *enc_right_;
};

#endif
