#include "clock.hpp"

using namespace std::chrono;

Stopwatch::Stopwatch(): 
  _start_time(high_resolution_clock::now()),
  _stop_time(_start_time), 
  _is_running(false) {}

void Stopwatch::start() {
  _start_time = high_resolution_clock::now();
  _is_running = true;
}

void Stopwatch::stop() {
  _stop_time = high_resolution_clock::now();
  _is_running = false;
}

double Stopwatch::get_milliseconds() {
  if(_is_running) {
    return (duration_cast<duration<double>>(high_resolution_clock::now() - _start_time)).count() * MILLISECOND_CONVERSION_SCALE;
  }
  return (duration_cast<duration<double>>(_stop_time - _start_time)).count() * MILLISECOND_CONVERSION_SCALE;
}