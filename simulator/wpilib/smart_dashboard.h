#pragma once

#include <map>
#include <vector>
#include <mutex>

class SmartDashboard {
 public:
  static void PutNumber(std::string key, double value);
  static void PutString(std::string key, std::string value);
  static void PutBoolean(std::string key, bool value);
  static double GetNumber(std::string key);
  static std::string GetString(std::string key);
  static bool GetBoolean(std::string key);
  static const std::map<std::string, std::string>& GetEntries();

 private:
  static std::mutex lock_;
  static std::map<std::string, std::string> values;
};
