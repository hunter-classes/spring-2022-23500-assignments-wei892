#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stack.h"
#include "queue.h"
#include <iostream>

TEST_CASE("Checking Stack Case"){
  Stack *s = new Stack();
  CHECK( s->is_empty() == 1);
  s->push(10);
  s->push(220);
  s->push(30);
  CHECK(s->is_empty()  == 0);
  int n = s->top();
  CHECK(n == 220);
  n = s->pop();
  CHECK(n == 220);
  n = s->pop();
  CHECK(n == 30);
  CHECK(s->is_empty() == 0);  
}

TEST_CASE(""){
  Queue *q = new Queue();
  CHECK(q->is_empty() == 1);
  int w = 6; 
  while (w > 0){
    q->enqueue(w);
    w--;
  }
  CHECK(q->is_full() == true);

  w = q->front();
  CHECK(w == 6);
  w = q->sequeue();
  CHECK( w == 6);
  w = q->sequeue();
  CHECK(w == 5);
  CHECK(q->is_full() == 0);

}
