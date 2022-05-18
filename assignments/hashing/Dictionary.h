#pragma once
#include "List.h"

class Dictionary{
 private:
  List *arr[10];

 public:
  Dictionary();
  ~Dictionary();

  int hashKey(Person *p);
  void insertPerson(Person *p);
  Person* retrievePerson(Person *p);
  std::string getAllKeys();
  
};
