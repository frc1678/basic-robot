#include "unitscpp/unitscpp.h"
#include <atomic>
#include <thread>

class Updateable {
public:
  Updateable();
  ~Updateable();
  virtual void update(Time dt) = 0;
  void start();
  void end();

private:
  std::thread _main;
  std::atomic<bool> _running;
};
