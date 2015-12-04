#include "state_machine.h"
#include <iostream>

StateMachine::StateMachine(std::string initial_state) : _first(initial_state) {

}

void StateMachine::start() {
  _current = _first;
  if (_states.count(_current)) {
    _states[_current].init();
  }
  else {
    std::cout << "No state found" << std::endl;
    // TODO(Kyle) Handle the case where the state does not exist
  }
}

void StateMachine::update() {
  if (_states.count(_current)) {
    std::string next = _states[_current].update();
    // std::cout << "State: " << _states[_current].name() << std::endl;
    if (next != "") {
      if (_states.count(next)) {
        _current = next;
        _states[_current].init();
      }
    }
  }
  else {
    std::cout << "No state found" << std::endl;
    // TODO(Kyle) Handle the case where the state does not exist
  }
}

void StateMachine::add_state(State& to_add) {
  _states[to_add.name()] = to_add;
}
