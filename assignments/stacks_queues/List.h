#pragma once

#include "Node.h"

class List{
 private:
  Node *head;
  int size;
  
 public:
  List();
  ~List();

  void insert(int value);
  bool contains(int value);
  int get(int loc);
  void remove(int loc);
  void reverse();
  std::string toString();
};
