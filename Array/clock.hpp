#ifndef CLOCK_H
#define CLOCK_H

#include <ctime>
#include <ratio>
#include <chrono>

#define MILLISECOND_CONVERSION_SCALE 1000

class Stopwatch {
public:
  Stopwatch();
  void start();
  void stop();
  double get_milliseconds();
private:
  std::chrono::high_resolution_clock::time_point _start_time;
  std::chrono::high_resolution_clock::time_point _stop_time;
  bool _is_running;
};

#endif