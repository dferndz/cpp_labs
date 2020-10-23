#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.hpp"

// default traces
std::vector<std::string> traces = {
  "./traces/basic.txt",
  "./traces/basic2.txt",
  "./traces/large.txt"
};

// file for reading traces
std::ifstream trace_file;

// number of traces
unsigned total_traces = 0;

// number of correct traces
unsigned correct_traces = 0;

// score
unsigned score = 0;
unsigned max_score = 0;

void evaluate_score(trace_result_t results);

int main(int argc, char *argv[]) {
  trace_result_t result;
  std::cout << "\n------- RUNNING TESTS -------"  << std::endl;
  for (int i = 0; i < traces.size(); i++) {
    trace_file.open(traces[i]);

    if (trace_file) {
      // run tester
      result = run_trace(trace_file);
      evaluate_score(result);
    } else {
      std::cout << "Trace file " << traces[i] << " not found." << std::endl;
    }

    trace_file.close();
  }

  std::cout << "---------- RESULTS ----------"  << std::endl;
  std::cout << "Correct traces: " << correct_traces << "/" << total_traces << std::endl;
  std::cout << "Score: " << score << "/" << max_score << std::endl << std::endl;
}

void evaluate_score(trace_result_t results) {
  if (results.correct) {
    std::cout << "Trace " << std::setw(3) << results.trace_number << " is CORRECT" << std::endl;
    correct_traces++;
  } else {
    std::cout << "Trace " << std::setw(3) << results.trace_number << " FAILED" << std::endl;
  }
  std::cout << " - Score: " << results.score << "/" << results.max_score <<  " | " << results.exec_time << " ms" << std::endl;
  total_traces++;
  score += results.score;
  max_score += results.max_score;
}