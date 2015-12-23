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
  return std::chrono::duration_cast<std::chrono::duration<float>>(start_ - std::chrono::high_resolution_clock::now()).count()*s;
}
