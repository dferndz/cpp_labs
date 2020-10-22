#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "my_sort.hpp"
#include "clock.hpp"

// default traces
std::vector<std::string> traces = {
  "./traces/simple.txt",
  "./traces/tuple.txt",
  "./traces/basic.txt",
  "./traces/large.txt",
  "./traces/very_large.txt"
};

// load array from file
void loadArray(std::ifstream &buff, int *a, size_t s) {
  for (int i = 0; i < s; i++) {
    if (!(buff >> a[i])) {
      std::cout << "Invalid trace file found." << std::endl;
      exit(1);
    }
    ;
  }  
}

// test if two arrays are equal
bool test(int *a, int *b, size_t s) {
  for (int i = 0; i < s; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  // array to sort
  int *nums;
  // expected result
  int *expected;
  // trace execution time limit
  double execution_time_limit;
  // order: a - asc or d - desc
  char o;
  // order flag ASC/DESC
  SORT_ORDER o_flag;
  // total execution time
  double total_time = 0;
  // total number of traces
  size_t total_traces = 0;
  // number of correct traces
  size_t correct_traces = 0;
  // input file
  std::ifstream file;
  // size of array
  size_t size;
  // current trace number
  size_t trace_num = 1;
  // stopwatch to measure performance
  Stopwatch s;

  // if argument is provided, load only the given trace file
  if (argc > 1) {
    traces = std::vector<std::string>();
    traces.push_back(argv[1]);
  }

  // run all traces
  for (size_t i = 0; i < traces.size(); i++) {
    file.open(traces[i]);

    // if trace is not found, skip it
    if (!file) {
      std::cout << "Did not find trace file: " << traces[i] << std::endl;
      continue;
    }

    // read size, order char and time limit
    file >> size;
    file >> o;
    file >> execution_time_limit;
    
    // imitialize arrays
    nums = new int[size];
    expected = new int[size];

    // read array to sort
    loadArray(file, nums, size);
    // read expected result
    loadArray(file, expected, size);

    // set the order flag
    if (o == 'a') o_flag = ASC;
    else if (o == 'd') o_flag = DESC;
    else {
      std::cout << "Invalid trace file found." << std::endl;
      exit(1);
    }

    // run sort function
    s.start();
    my_sort(nums, size, o_flag);
    s.stop();

    // test correctness of sort
    if(test(nums, expected, size) && s.get_milliseconds() < execution_time_limit) {
      std::cout << "Trace " << trace_num << " is CORRECT ";
      correct_traces++;
    } else {
      std::cout << "Trace " << trace_num << " FAILED ";
      if (s.get_milliseconds() >= execution_time_limit) {
        std::cout << "Time limit exceeded ";
      }
    }
    std::cout << s.get_milliseconds() << " ms" << std::endl;
    total_time += s.get_milliseconds();
    total_traces++;

    // cleanup after each trace
    file.close();
    delete [] nums;
    delete [] expected;
    trace_num++;
  }
  // general stats
  std::cout << "Correctness: " << correct_traces << "/" << total_traces << std::endl;
  std::cout << "Total execution time: " << total_time << " ms" << std::endl;
}