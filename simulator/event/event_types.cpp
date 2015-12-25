#include "state_change.h"
#include "simulator/model/robot_position.h"
#include "simulator/wpilib/speed_controller.h"
#include "simulator/wpilib/encoder.h"
#include "simulator/wpilib/solenoid.h"
#include "simulator/model/intake.h"

int RobotPositionData::kEventType = __COUNTER__;
int StateChangeData::kEventType = __COUNTER__;
int SpeedControllerData::kEventType = __COUNTER__;
int EncoderData::kEventType = __COUNTER__;
int SolenoidData::kEventType = __COUNTER__;
int IntakeData::kEventType = __COUNTER__;
