#include "intake.h"
#include "simulator/event/event_manager.h"

IntakePlant::IntakePlant(int channel_sol, int channel_motor) {
  EventManager::GetInstance()->RegisterListener(SolenoidData::kEventType, [=](EventData* data) {
    SolenoidData* sol_data = (SolenoidData*)data;
    if (sol_data->channel == channel_sol) solenoid_on_ = sol_data->open;
  });
}

void IntakePlant::Update(Time dt) {
  Angle max = solenoid_on_ ? 80*deg : 0*deg;
  position += dt*(2*(max-position)/s);
  EventManager::GetInstance()->QueueEvent(Event(new IntakeData(position)));
}
