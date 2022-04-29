#include "queue.h"

Queue::Queue(){
  head = 0;
  tail = 0;
  size = 7;
  queue = new int[size];
}

Queue::~Queue(){
  delete []queue;
  head, tail, size = 0;
}

void Queue::enqueue(int n){
  //check if full
  if (is_full()) throw QUEUE_ERR_FULL;
  //if not full, add value
  queue[tail%6] = n;
  tail++;
}

int Queue::sequeue(){
  if (is_empty()) throw QUEUE_ERR_EMPTY;
  int temp = queue[head];
  head++;
  return temp;
}

int Queue::front(){
  if (is_empty()) throw QUEUE_ERR_EMPTY;
  return queue[head];
}

bool Queue::is_empty(){
  std::cout.setf(std::ios::boolalpha);
  if (head - tail == 0){
    return true;
  }
  return false;
}

bool Queue::is_full(){
  if (tail-head >= 6){
    return true;
  }
  return false;
}
