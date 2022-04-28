#pragma once

class BSTree{
 private:
  Node *root;
 public:
  BSTree();
  void insert(int d);
  std::string get_debug_string();
  std::string traverse(Node *r);
  std::string get_debugger_Rec();
  void setup();
};
