#pragma once
#include <iostream>

#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

class Queue{
private:
  int size;
  int *queue;
  int head;
  int tail;
public:
  Queue();
  ~Queue();
  void enqueue(int n); //add an item to the back of the queue
  int sequeue(); //remove and return the item from the front of the queue
  int front(); //return but do not remove the item from the front of the queue
  bool is_empty();
  bool is_full(); //u should not grow the array once you create it, just let it fill up
};
