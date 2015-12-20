#include "muan/statemachine/state_machine.h"
#include "frc1678/robot_subsystems.h"
#include <WPILib.h>
#include <memory>

class AutoStateMachine : public StateMachine {
 public:
  AutoStateMachine(RobotSubsystems& subsystems);

 private:
  std::unique_ptr<Timer> timer;
};
