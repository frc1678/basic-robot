#include "updateable.h"
#include <chrono>
#include <iostream>

Updateable::Updateable(Frequency tick_rate) {
  Time loop_time = 1 / tick_rate;
  _main = std::thread([this, loop_time]() {
    // Wait for it to start
    while (!this->_running) {
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    while (this->_running) {
      // Capture the current time, adding 5 milliseconds to ensure exact timing
      std::chrono::system_clock::time_point until =
          std::chrono::system_clock::now() +
          std::chrono::milliseconds((int)loop_time.to(ms));
      update(loop_time);
      // Maintain timing
      std::this_thread::sleep_until(until);
    }
  });
}

Updateable::~Updateable() { stop(); }

void Updateable::start() { _running = true; }

void Updateable::stop() { _running = false; }

void Updateable::join() {
  stop();
  _main.join();
}
