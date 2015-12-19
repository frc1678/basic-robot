#include "state.h"

State::State(std::string name, std::function<void()> init_func,
             std::function<std::string()> update_func)
    : _name(name), _init_func(init_func), _update_func(update_func) {}

State::State(std::string name, std::function<std::string()> update_func)
    : State(name, []() {}, update_func) {}

State::State(std::string name)
    : State(name, []() {}, []() -> std::string { return ""; }) {}

State::State() : State("Unnamed state") {}

State::~State() {}

void State::init() { _init_func(); }

std::string State::update() { return _update_func(); }

std::string State::name() { return _name; }
