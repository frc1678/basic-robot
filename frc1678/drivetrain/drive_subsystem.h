#include "muan/multithreading/updateable.h"
#include <WPILib.h>

class DriveSubsystem : public Updateable {
 public:
  DriveSubsystem();
  ~DriveSubsystem();
  virtual void update(Time dt) override;
  void drive_distance(Length dist);
  void drive_tank(Velocity right, Velocity left);

 private:
  RobotDrive* _drivetrain;
  Length target_dist;
  Velocity target_velocity_left, target_velocity_right;
  Encoder* enc_left, *enc_right;
};