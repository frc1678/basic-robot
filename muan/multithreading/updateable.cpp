#include "updateable.h"
#include <chrono>

Updateable::Updateable() {
  _main = std::thread([&]() {
    // Wait for it to start
    while (!_running) {
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    while (_running) {
      std::chrono::time_point until =
          std::chrono::system_clock::now() + std::chrono::milliseconds(5);
      update(5 * ms);
      std::this_thread::sleep_until(until);
    }
  });
}
