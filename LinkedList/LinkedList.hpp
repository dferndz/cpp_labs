#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

typedef unsigned long size_t;

class EmptyListException : public std::logic_error
{
public:
  EmptyListException(): logic_error("The list is empty.") {}
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
  void insert_back(const _T& val) {

  }
  //insert an element in the front of the list
  //arg1 - the value to be inserted
  void insert_front(const _T& val) {

  }
  //pop the element in the back of the list
  _T pop_back() {
    throw EmptyListException();
  }
  //pop the element in the front of the list
  _T pop_front() {
    throw EmptyListException();
  }
  //get the size of the list
  size_t size() {
    return 0;
  }
  //reverse the list
  void reverse() {

  }
  //return true if list is empty
  bool is_empty() {
    return true;
  }
  //return element at position n
  _T& at(size_t n) {
    throw EmptyListException();
  }
  //get bottom value, return the removed value
  _T& bottom() {
    throw EmptyListException();
  }
  //get top value, return the removed value
  _T& top() {
    throw EmptyListException();
  }
protected:
//head of list
  node_t<_T> *_head;
  //you may add more protected members
};

#endif
