#pragma once

#include <chrono>
#include <iomanip>
#include <ctime>
#include <thread>
#include <string>
#include <sstream>

#include "types.hpp"

//TODO 应该改成微秒值
typedef std::time_t Time;

inline Time Now() {
  const auto now = std::chrono::system_clock::now();
  return std::chrono::system_clock::to_time_t(now);
}

inline void Sleep(int ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}


inline string FormatTime(const Time& t, const std::string& fmt) {
  std::ostringstream oss;
  oss << std::put_time(std::localtime(&t), fmt.c_str());
  //oss.flush();
  return oss.str();
}

inline Time ParseTime(const std::string& str, const std::string& fmt) {
  std::tm tm{};
  std::istringstream iss(str);
  iss >> std::get_time(&tm, fmt.c_str());
  return std::mktime(&tm);
}

#define LocaleTime "%Y-%m-%d %H:%M:%S"

//using Seconds = std::chrono::duration<double>;
//using Milliseconds = std::chrono::duration<double, std::milli>;
//using Microseconds = std::chrono::duration<double, std::micro>;

