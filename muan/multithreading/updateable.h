#ifndef MUAN_MULTITHREADING_UPDATEABLE
#define MUAN_MULTITHREADING_UPDATEABLE

#include "unitscpp/unitscpp.h"
#include <atomic>
#include <thread>

class Updateable {
 public:
  Updateable(Frequency tick_rate);
  ~Updateable();
  virtual void update(Time dt) = 0;
  void start();
  void stop();
  void join();

 private:
  std::thread _main;
  std::atomic<bool> _running;
};

#endif
