#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

typedef unsigned long size_t;

class NotImplementedException : public std::logic_error
{
public:
  NotImplementedException(): logic_error("Function not yet implemented.") {}
};

template<class _T>
struct node_t {
  _T value;
  node_t<_T> *next;
  node_t(const _T &val): value(val), next(nullptr) {}
};

template<class _T>
class LinkedList {
public:
  //default constructor
  LinkedList() {

  }
  ~LinkedList() {

  }
  //insert an element in the back of the list
  //arg1 - the value to be inserted
  void insert_back(const _T&) {
    throw NotImplementedException();
  }
  //insert an element in the front of the list
  //arg1 - the value to be inserted
  void insert_front(const _T&) {
    throw NotImplementedException();
  }
  //pop the element in the back of the list
  _T pop_back() {
    throw NotImplementedException();
  }
  //pop the element in the front of the list
  _T pop_front() {
    throw NotImplementedException();
  }
  //get the size of the list
  size_t size() {
    throw NotImplementedException();
  }
  //reverse the list
  void reverse() {
    throw NotImplementedException();
  }
  //return true if list is empty
  bool is_empty() {
    throw NotImplementedException();
  }
  //return element at position n
  _T& at(size_t n) {
    throw NotImplementedException();
  }
  //get bottom value
  _T& bottom() {
    throw NotImplementedException();
  }
  //get top value
  _T& top() {
    throw NotImplementedException();
  }
  //get initial node
  //WARNING do not modify this function
  node_t<_T>* get_head() { return _head;  }
protected:
//head of list
  node_t<_T> *_head;
  //you may add more protected members
};

#endif
