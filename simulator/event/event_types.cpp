#include "state_change.h"
#include "simulator/model/robot_position.h"
#include "simulator/wpilib/speed_controller.h"
#include "simulator/wpilib/encoder.h"

int RobotPositionData::kEventType = __COUNTER__;
int StateChangeData::kEventType = __COUNTER__;
int SpeedControllerData::kEventType = __COUNTER__;
int EncoderData::kEventType = __COUNTER__;
