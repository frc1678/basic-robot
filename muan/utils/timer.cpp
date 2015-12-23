#include "timer.h"

Timer::Timer() {
  Start();
}

void Timer::Start() {
  start_ = std::chrono::high_resolution_clock::now();
}

void Timer::Reset() {
  start_ = std::chrono::high_resolution_clock::now();
}

Time Timer::Get() {
  return start_ - std::chrono::high_resolution_clock::now();
}
