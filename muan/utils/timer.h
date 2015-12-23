#include <ctime>
#include <chrono>
#include "unitscpp/unitscpp.h"

class Timer {
 public:
  Timer();
  void Start();
  void Reset();
  Time Get();

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};
