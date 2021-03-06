#include <iostream>
#include "Node.h"
#include "List.h"
#include "stack.h"
#include "queue.h"


int main(){

  //=====stacks=====//
  Stack *s = new Stack();
  std::cout << "Stack empty: " << s->is_empty() << std::endl;
  s->push(1);
  s->push(2);
  s->push(3);
  std::cout << "Stack empty: " << s->is_empty() << std::endl;
  int n = s->top();
  std::cout << std::to_string(n) << std::endl; //will return 1
  n = s->pop();
  std::cout << std::to_string(n) << std::endl; //this returns the top number
  n = s->pop();
  std::cout << std::to_string(n) << std::endl; //this will be 2, since we removed it in the previous pop

  std::cout << "Empty? " << s->is_empty() << std::endl;
  if (s->is_empty() != 1) {
    n = s->top();
  std::cout << std::to_string(n) << std::endl;
  }  // need to use is empty, pop, top and push
  
  //=====trying queue=====//
  Queue *q = new Queue();
  std::cout << "Is queue empty? " << q->is_empty() << std::endl;
  
  int w = 6; 
  while (w > 0){
    q->enqueue(w);
    w--;
  }
  std::cout << "Is queue full? " << q->is_full() << std::endl;

  w = q->front();
  std::cout << std::to_string(w) << std::endl;
  w = q->sequeue();
  std::cout << std::to_string(w) << std::endl;
  w = q->sequeue();
  std::cout << std::to_string(w) << std::endl;
      
  return 0;
}
