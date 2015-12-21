/*
 * updateable.cpp
 *
 *  Created on: Dec 18, 2015
 *  Copyright 2015 Citrus Circuits
 *      Author: Kyle Stachowicz
 */

#include "updateable.h"
#include <chrono>
#include <iostream>

Updateable::Updateable(Frequency tick_rate) {
  Time loop_time = 1 / tick_rate;
  main_ = std::thread([this, loop_time]() {
    // Wait for it to start
    while (!this->running_) {
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    while (this->running_) {
      // Capture the current time, adding 5 milliseconds to ensure exact timing
      std::chrono::system_clock::time_point until =
          std::chrono::system_clock::now() +
          std::chrono::milliseconds(static_cast<int>(loop_time.to(ms)));
      Update(loop_time);
      // Maintain timing
      std::this_thread::sleep_until(until);
    }
  });
}

Updateable::~Updateable() { Stop(); }

void Updateable::Start() { running_ = true; }

void Updateable::Stop() { running_ = false; }

void Updateable::Join() {
  Stop();
  main_.join();
}
