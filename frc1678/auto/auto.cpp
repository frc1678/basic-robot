#include "auto.h"
#include <WPILib.h>

AutoStateMachine::AutoStateMachine(RobotSubsystems& subsystems)
    : StateMachine("init") {
  timer = std::unique_ptr<Timer>(new Timer());
  State init("init", [&, this]() { return "drive"; });

  State drive(
      "drive",
      [&, this]() {
        subsystems.drive.drive_distance(15 * ft);
        /* subsystems.claw.move_to(.2*rad); */
      },
      [&]() {
        if (/* subsystems.drive.is_done()*/ true /* && subsystems.claw.is_done */) {
          return "score";
        }
        return "";
      });

  State score("score",
              [this]() {
                timer->Reset();
                timer->Start();
              },
              [&, this]() {
                /* subsystems.claw.spit() */
                return (timer->Get() > 2) ? "done" : "";
              });

  State done("done", []() { return ""; });

  add_state(init);
  add_state(drive);
  add_state(score);
  add_state(done);
}
