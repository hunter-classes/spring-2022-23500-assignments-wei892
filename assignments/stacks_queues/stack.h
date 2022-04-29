#pragma once
#include "List.h"

#define STACK_ERR_EMPTY 1
#define STACK_ERR_FULL 2
#define STACK_ERR_OTHER 4


class Stack{
 private:
  int size;
  List *stack;
  
 public:
  Stack();
  ~Stack();
  void push(int n); // add an item to the top
  int pop(); // remove and return an item from the top of the stack
  int top(); // returns but doesn't remove the value on top
  bool is_empty(); // returns true if stack is empty
};
