#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include "allocator.hpp"
#include "LinkedList.hpp"

using namespace std;

vector<string> traces = {
  "./traces/basic.txt"
};

LinkedList<int> *linked_list;
list<int> *test_list;
bool is_trace_valid;
bool is_memory_valid;
size_t total_traces;
size_t correct_traces;

bool is_mem_valid();

void process_command(string cmd, ifstream &file);

int main(int argc, char *argv[]) {
  string command;
  ifstream trace_file;
  total_traces = 0;
  correct_traces = 0;

  cout << "\n------ TESTING ------" << endl;

  for (int i = 0; i < traces.size(); i++) {
    trace_file.open(traces[i]);

    if (trace_file) {
      total_traces++;
      is_trace_valid = true;
      is_memory_valid = true;

      while(trace_file >> command) {
        process_command(command, trace_file);
      }

      trace_file.close();

      if (is_trace_valid) {
        cout << "Trace " << i + 1 << " is CORRECT" << endl;
        correct_traces++;
      } else {
        cout << "Trace " << i + 1 << " FAILED" << endl;
        if (!is_memory_valid) {
          cout << "Not all memory blocks were deallocated." << endl;
        }
      }
    } else {
      cout << "Trace file " << traces[i] << " not found." << endl;
    }
  }

  cout << "------ RESULTS ------" << endl;
  cout << "Score: " << correct_traces << "/" << total_traces << endl << endl;

  return 0;
}

bool is_mem_valid() {
  return get_status() != INVALID_PTR;
}

void process_command(string cmd, ifstream &file) {
  int val;
  int test_val;
  if (cmd == "ib") {
    file >> val;
    linked_list->insert_back(val);
    test_list->push_back(val);
  }
  if (cmd == "if") {
    file >> val;
    linked_list->insert_front(val);
    test_list->push_front(val);
  }
  if (cmd == "r") {
    linked_list->reverse();
    test_list->reverse();
  }
  if (cmd == "pf") {
    try {
      val = linked_list->pop_front();
    } catch (exception &e) {
      is_trace_valid = false;
    }
    test_val = test_list->front();
    test_list->pop_front();

    if (val != test_val) {
      is_trace_valid = false;
    }
  }
  if (cmd == "pb") {
    try {
      val = linked_list->pop_back();
    } catch (exception &e) {
      is_trace_valid = false;
    }
    test_val = test_list->back();
    test_list->pop_back();

    if (val != test_val) {
      is_trace_valid = false;
    }
  }

  if (cmd == "n") {
    mm_init();
    linked_list = new LinkedList<int>();
    test_list = new list<int>();
  }

  if (cmd == "d") {
    delete linked_list;
    delete test_list;
    if(!is_mem_valid()) {
      is_trace_valid = false;
      is_memory_valid = false;
    }
  }
}