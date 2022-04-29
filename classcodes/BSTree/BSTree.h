#pragma once
#include <string>

class BSTree{
 private:
  Node *root;
 public:
  BSTree();
  void insert(int d);
  std::string get_debug_string();
  std::string recursion(Node *r);
  std::string get_debugger_Rec();
  int search(int value);
  void insertNew(int value);
  void setup();
};
