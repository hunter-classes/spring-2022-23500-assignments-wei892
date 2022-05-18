#include <iostream>
#include "Dictionary.h"

int main(){
  Dictionary *celebrities = new Dictionary();

  Person *c1 = new Person("Pitt","Brad", 1);
  Person *c2 = new Person("Johnson","Dwayne", 2);
  Person *c3 = new Person("Perry","Katie",3);
  Person *c4 = new Person("Stone", "Emma", 4);
  Person *c5 = new Person("Depp", "Johnny", 5);

  std::cout << "Before insertion:" << std::endl;
  std::cout << "Names in Dictionary: " << std::endl;
  
  celebrities->insertPerson(c1);
  celebrities->insertPerson(c2);
  celebrities->insertPerson(c3);
  celebrities->insertPerson(c4);
  celebrities->insertPerson(c5);

  std::cout << "\nAfter insertion:" << std::endl;
  std::cout << "Names in Dictionary: " << std::endl;
  std::cout << celebrities->getAllKeys() << std::endl;

  
  std::cout << "Retrieving person: c3" << std::endl;
  std::cout << celebrities->retrievePerson(c2)->get_name() << std::endl;
  
  std::cout << "Retrieving person: c5" << std::endl;
  std::cout << celebrities->retrievePerson(c5)->get_name() << std::endl;

  
  return 0;
}
