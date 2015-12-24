#include "smart_dashboard.h"
#include <iostream>

std::mutex SmartDashboard::lock_;
std::map<std::string, std::string> SmartDashboard::values;

void SmartDashboard::PutNumber(std::string key, double value) {
  std::lock_guard<std::mutex> lock(lock_);
  values[key] = std::to_string(value);
  std::cout << "Put value " << values[key] << " into " << key << std::endl;
}

void SmartDashboard::PutString(std::string key, std::string value) {
  std::lock_guard<std::mutex> lock(lock_);
  values[key] = value;
}

void SmartDashboard::PutBoolean(std::string key, bool value) {
  std::lock_guard<std::mutex> lock(lock_);
  values[key] = (value == true ? "True" : "False");
}

double SmartDashboard::GetNumber(std::string key) {
  std::lock_guard<std::mutex> lock(lock_);
  return std::stod(values[key]);
}

std::string SmartDashboard::GetString(std::string key) {
  std::lock_guard<std::mutex> lock(lock_);
  return values[key];
}

bool SmartDashboard::GetBoolean(std::string key) {
  std::lock_guard<std::mutex> lock(lock_);
  return values[key] == "True";
}

const std::map<std::string, std::string>& SmartDashboard::GetEntries() {
  return values;
}
