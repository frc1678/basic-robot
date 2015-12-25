#include "simulator/wpilib/solenoid.h"
#include "unitscpp/unitscpp.h"

struct IntakeData : public EventData {
 public:
  IntakeData(Angle a) : EventData(kEventType), angle(a) {}
  Angle angle;
  static int kEventType;
};

class IntakePlant {
 public:
  IntakePlant(int channel_sol, int channel_motor);
  void Update(Time dt);

 private:
  Angle position = 0*rad;
  bool solenoid_on_ = false;
};
