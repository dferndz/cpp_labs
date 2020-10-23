#include <iostream>
#include <algorithm>
#include "utils.hpp"
#include "clock.hpp"
#include "operations.hpp"
#include "tester.hpp"

bool is_sorted = false;

// load array from file
void load_array(std::ifstream &buff, int *a, size_t s) {
  for (int i = 0; i < s; i++) {
    if (!(buff >> a[i])) {
      std::cout << "Invalid trace file found." << std::endl;
      exit(1);
    }
    ;
  }  
}

// test if two arrays are equal
bool check_equal(int *a, int *b, size_t s) {
  for (int i = 0; i < s; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

// cope an array
void copy_array(int *des, int *src, size_t s) {
  for (size_t i = 0; i < s; i++) {
    des[i] = src[i];
  }
}

bool contains(int *a, size_t s, int target) {
  for (int i = 0; i < s; i++) {
    if (a[i]==target) return true;
  }
  return false;
}

void run_s(std::ifstream &file, int *array, int *test_array, size_t s, trace_result_t &r) {
  Stopwatch sw;
  int target;
  int pos;

  r.max_score++;

  file >> target;

  sw.start();
  pos = search(array, s, target);
  sw.stop();

  r.exec_time += sw.get_milliseconds();

  if (contains(array, s, target)) {
    if (pos >= 0 && pos < s) {
      if (array[pos] == target) {
        r.score++;
      } else {
        r.correct = false;
      }
    } else {
      r.correct = false;
    }
  } else {
    if (pos == -1) {
      r.score++;
    } else {
      r.correct = false;
    }
  }

  if (!check_equal(array, test_array, s)) {
    r.score--;
    r.correct = false;
  }
}

void run_b(std::ifstream &file, int *array, int *test_array, size_t s, trace_result_t &r) {
  Stopwatch sw;
  int target;
  int pos;

  r.max_score++;

  file >> target;

  if (!is_sorted) {
    test_sort(array, s, 0);
    test_sort(test_array, s, 0);
    is_sorted = true;
  }
  

  sw.start();
  pos = binary_search(array, s, target);
  sw.stop();

  r.exec_time += sw.get_milliseconds();

  if (contains(array, s, target)) {
    if (pos >= 0 && pos < s) {
      if (array[pos] == target) {
        r.score++;
      } else {
        r.correct = false;
      }
    } else {
      r.correct = false;
    }
  } else {
    if (pos == -1) {
      r.score++;
    } else {
      r.correct = false;
    }
  }

  if (!check_equal(array, test_array, s)) {
    r.score--;
    r.correct = false;
  }
}

void run_o(std::ifstream &file, int *array, int *test_array, size_t s, trace_result_t &r) {
  Stopwatch sw;
  char o;

  r.max_score++;

  file >> o;

  is_sorted = false;

  if (o == 'a')
    test_sort(test_array, s, 0);
  else
    test_sort(test_array, s, 1);

  sw.start();
  my_sort(array, s, (o == 'a' ? ASC : DESC));
  sw.stop();

  r.exec_time += sw.get_milliseconds();

  if (check_equal(array, test_array, s)) {
    r.score++;
  } else {
    r.correct = false;
  }
}

void run_r(std::ifstream &file, int *array, int *test_array, size_t s, trace_result_t &r) {
  Stopwatch sw;

  r.max_score++;

  test_reverse(test_array, s);

  is_sorted = false;

  sw.start();
  reverse(array, s);
  sw.stop();

  r.exec_time += sw.get_milliseconds();

  if (check_equal(array, test_array, s)) {
    r.score++;
  } else {
    r.correct = false;
  }
}

// evaluate a trace file
trace_result_t run_trace(std::ifstream &file) {
  static unsigned trace_number = 0;
  trace_result_t results;
  int *array;
  int *test_array;
  size_t size;
  double time_limit;
  char op;
  is_sorted = false;

  results.trace_number = ++trace_number;

  file >> size;
  file >> time_limit;

  array = new int[size];
  test_array = new int[size];

  load_array(file, array, size);
  copy_array(test_array, array, size);


  while(file >> op) { 
    switch (op)
    {
    case 's':
      run_s(file, array, test_array, size, results);
      break;
    
    case 'b':
      run_b(file, array, test_array, size, results);
      break;
    
    case 'o':
      run_o(file, array, test_array, size, results);
      break;
    
    case 'r':
      run_r(file, array, test_array, size, results);
    
    default:
      break;
    }
  }

  if (results.exec_time > time_limit) {
    results.score = 0;
    results.correct = false;
    results.time_exc = true;
  }

  delete [] array;
  delete [] test_array;

  return results;
}