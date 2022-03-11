#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "List.h"
#include "ONode.h"
#include "OList.h"


#include <iostream>

TEST_CASE("Testing Insertion and using get location to check if increasing"){

  OList *o1 = new OList();

  o1->insert(4);
  o1->insert(5);
  o1->insert(8);
  o1->insert(3);
  o1->insert(6);
  o1->insert(9);
  o1->insert(7);
  o1->insert(2);
  o1->insert(10);
  o1->insert(1);

  CHECK(o1->get(0) == 1);
  CHECK(o1->get(1) == 2);
  CHECK(o1->get(2) == 3);
  CHECK(o1->get(3) == 4);
  CHECK(o1->get(4) == 5);
  CHECK(o1->get(5) == 6);
  CHECK(o1->get(6) == 7);
  CHECK(o1->get(7) == 8);
  CHECK(o1->get(8) == 9);
  CHECK(o1->get(9) == 10);
} 


TEST_CASE("Testing Deletion"){

  OList *o1 = new OList();

  o1->insert(4);
  o1->insert(5);
  o1->insert(8);
  o1->insert(3);
  o1->insert(6);
  o1->insert(9);
  o1->insert(7);
  o1->insert(2);
  o1->insert(10);
  o1->insert(1);

  CHECK(o1->get(0) == 1);
  CHECK(o1->get(1) == 2);
  o1->remove(1);
  CHECK(o1->get(1) == 3);
  CHECK(o1->get(2) == 4);
  o1->remove(2);
  CHECK(o1->get(3) == 6);
} 
