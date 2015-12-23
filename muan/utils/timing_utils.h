#ifndef MUAN_UTILS_TIMING_UTILS_H_
#define MUAN_UTILS_TIMING_UTILS_H_

#include <chrono>
#include <thread>
#include "unitscpp/unitscpp.h"

void sleep_thread(Time t) {
  std::this_thread::sleep_for(std::chrono::milliseconds((int)t.to(ms)));
}

Time now() {
  return std::chrono::duration_cast<std::chrono::duration<float>>(std::chrono::system_clock::now().time_since_epoch()).count()*s;
}

void sleep_until(Time t) {
  auto as_time_point = std::chrono::time_point<std::chrono::system_clock>(std::chrono::milliseconds((int)t.to(ms)));
  std::this_thread::sleep_until(as_time_point);
}

#endif // MUAN_UTILS_TIMING_UTILS_H_
