#pragma once
#include "Node.h"

class List{
 private:
  Node *head;
  int size;

 public:
  List();
  ~List();

  void insert(Person *p);
  void insert(int loc, Person *p);

  bool contains(Person *p);
  void remove(int loc);
  Person* get(std::string name);
  int length();
  std::string toString(); 
  
};
