#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary(){
  //iterating through array and adding linked list
  for (int i = 0; i < 10; i++){
    arr[i] = new List();
  }
}

Dictionary::~Dictionary(){
  for (int i = 0; i < 10; i++){
    delete arr[i];
  }

  //delete[] arr;
  //arr = nullptr;
}

//referenced from the website's simple hash function for string
int Dictionary::hashKey(Person *p){
  std::string fullname = p->get_name();
  //char ch[];
  //ch = fullname.toCharArray();
  int sum = 0;
  for (int i = 0; i<fullname.length(); i++){
    char c = fullname[i];
    sum += int(c);
  }

  return sum%10;
}

void Dictionary::insertPerson(Person *p){
  //find its position in the array using the hash key
  int key = hashKey(p);
  arr[key]->insert(p);
}

Person*  Dictionary::retrievePerson(Person *p){
  //return null if not in the dictionary
  //use the hashkey to traverse through

  int key = hashKey(p);
  if (arr[key] == nullptr){
    return nullptr;
  }
  else{
    return arr[key]->get(p->get_name());
  }
}

std::string Dictionary::getAllKeys(){
  //prints the name of all the people in the dictionary
  std::string allKeys = "";
  for (int i = 0; i<10; i++){
    allKeys +=  "-> " + arr[i]->toString();
  }
  return allKeys;
}
