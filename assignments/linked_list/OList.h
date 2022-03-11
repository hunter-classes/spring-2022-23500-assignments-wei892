#pragma once

#include "ONode.h"

class OList{
 private:
  ONode *head;
  int size;
  
 public:
  //constructor
  OList();
  //destructor
  ~OList();

  //insert a new node with value in its proper location
  void insert(int value);
  //returns a string presentation of the full list
  std::string toString();
  //retruns true if value is in the list, false otherwise
  bool contains(int value);
  //returns the value at location
  int get(int loc);
  //returns the value at loc
  void remove(int loc);
  //reverse the pointers
  void reverse();
};
