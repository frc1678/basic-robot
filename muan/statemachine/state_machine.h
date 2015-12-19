#include <string>
#include <map>
#include "state.h"

class StateMachine {
 public:
  StateMachine(std::string initial_state);
  void start();
  void update();

 protected:
  void add_state(State& to_add);

 private:
  std::map<std::string, State> _states;
  std::string _first, _current;
};
