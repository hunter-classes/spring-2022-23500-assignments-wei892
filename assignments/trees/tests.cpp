#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.h"
#include <iostream>

TEST_CASE("Checking sum of each level"){
  Tree *t = new Tree();
  t->insert(11);
  t->insert(4);
  t->insert(8);
  t->insert(7);
  t->insert(15);
  t->insert(17);
  t->insert(12);

  int sum = t->sum(0);
  CHECK(sum == 11);
  sum = t->sum(1);
  CHECK(sum == 19);
  sum = t->sum(2);
  CHECK(sum == 37);
}

TEST_CASE("Checking height of tree"){
  Tree *t = new Tree();
  t->insert(11);
  t->insert(4);
  t->insert(8);
  t->insert(7);
  t->insert(15);
  t->insert(17);
  t->insert(12);

  int height = t->findHeight();
  CHECK(height == 4);

  height = t->findHeight();
  t->insert(19);
  CHECK(height == 4);


  height = t->findHeight();
  t->insert(20);
  CHECK(height == 4);
  height = t->findHeight();
  t->insert(22);
  CHECK(height == 5);
}

TEST_CASE("Checking count leaves"){
  Tree *t = new Tree();
  t->insert(11);
  t->insert(4);
  t->insert(8);
  t->insert(7);
  t->insert(15);
  t->insert(17);
  t->insert(12);

  int numLeaves = t->countLeaves();
  CHECK(numLeaves == 3);

  t->deleteNode(17);
  numLeaves = t->countLeaves();
  CHECK(numLeaves == 2);
}

TEST_CASE("Checking delete function"){
  Tree *t = new Tree();
  t->insert(11);
  t->insert(4);
  t->insert(8);
  t->insert(7);
  t->insert(15);
  t->insert(17);
  t->insert(12);

   try {
    int x  = t->search(8);
    CHECK(x == 8);
  } catch (int e){
    CHECK(e == 1);
  }
  t->deleteNode(8);
   try {
    int x  = t->search(8);
    CHECK(x == 8);
  } catch (int e){
    CHECK(e == 1);
  }

    try {
    int x  = t->search(17);
    CHECK(x == 17);
  } catch (int e){
    CHECK(e == 1);
  }
    t->deleteNode(17);
     try {
    int x  = t->search(17);
    CHECK(x == 17);
  } catch (int e){
    CHECK(e == 1);
  }

   
}

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
