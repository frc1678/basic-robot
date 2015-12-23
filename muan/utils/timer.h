#include <ctime>
#include <chrono>

class Timer {
 public:
  Timer();
  void Start();
  void Reset();
  Time Get();
 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_
};
