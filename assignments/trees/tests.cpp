#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.h"
#include <iostream>


TEST_CASE("checking rsearch"){
  Tree *t = new Tree();
  t->insert(11);
  t->insert(4);
  t->insert(8);
  t->insert(7);
  t->insert(15);
  t->insert(17);
  t->insert(12);

  
  try {
    int x  = t->search(7);
    CHECK(x == 7);
  } catch (int e){
    CHECK(e == 1);
  }
  
  try {
    int x  = t->search(13);
    CHECK(x == 13);
  } catch (int e){
    CHECK(e == 1);
  }

  
  try {
    int x  = t->search(17);
    CHECK(x == 17);
  } catch (int e){
    CHECK(e == 1);
  }

  
  try {
    int x  = t->search(11);
    CHECK(x == 11);
  } catch (int e){
    CHECK(e == 1);
  }

  
  try {
    int x  = t->search(3);
    CHECK(x == 3);
  } catch (int e){
    CHECK(e == 1);
  }
}
