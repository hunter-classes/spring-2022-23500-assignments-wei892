#include <iostream>
#include "stack.h"

Stack::Stack(){
  stack = new List();
  size = 0;
}

Stack::~Stack(){
  delete stack;
}

void Stack::push(int n){
  stack->insert(n);
  size++;
}

int Stack::pop(){
  if (size <= 0) throw STACK_ERR_EMPTY;
  int temp = stack->get(size-1);
  stack->remove(size-1);
  size--;
  return temp;
}

int Stack::top(){
  if (stack < 0) throw STACK_ERR_EMPTY;
  return stack->get(size-1);
}

bool Stack::is_empty(){
  return size == 0;
}
