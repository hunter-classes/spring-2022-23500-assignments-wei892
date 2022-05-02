#pragma once
#include <iostream>
#include "Node.h"

class Tree{
 private:
  Node *root;
  std::string recursion(Node *r);
  int rsearch(int value, Node *p);
  void rinsert(int value, Node *p);
  int treeSum(Node *n);
public:
  Tree();
  void setup();
  std::string get_debug_string();	
  std::string printTree_Rec();
  int search(int value);
  int rsearch(int value);
  void insert(int value);
  void rinsert(int value);
  int treeSum();
};
