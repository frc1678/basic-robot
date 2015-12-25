#include "muan/statemachine/state_machine.h"

class AutoStateMachine : public StateMachine {
 public:
  AutoStateMachine(RobotDrive* drive) : StateMachine("drive") {
    State drive_s("drive", [=](){
      if (++(this->i) > 10000) return "stop";
      else drive->TankDrive(1.0, 1.0);
      return "";
    });
    AddState(drive_s);
  }
  int i = 0;
};
