#include <fstream>
#include <string>

struct trace_result_t {
  unsigned score;
  unsigned max_score;
  double exec_time;
  bool correct;
  unsigned trace_number;
  bool time_exc;

  trace_result_t(): score(0), max_score(0), exec_time(0), correct(true), trace_number(0), time_exc(false) {}
};

// load array from file
void load_array(std::ifstream &buff, int *a, size_t s);

// copy an array
void copy_array(int *des, int *src, size_t s);

// test if two arrays are equal
bool check_equal(int *a, int *b, size_t s);

bool contains(int *a, size_t s, int target);

// run a trace
trace_result_t run_trace(std::ifstream &file);