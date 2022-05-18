#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Dictionary.h"

TEST_CASE("Testing dictionary.cpp"){
  Dictionary *clebrities = new Dictionary();

  Person *c1 = new Person("Pitt","Brad", 1);
  Person *c2 = new Person("Johnson","Dwayne", 2);
  Person *c3 = new Person("Perry","Katie",3);
  Person *c4 = new Person("Stone", "Emma", 4);
  Person *c5 = new Person("Depp", "Johnny", 5);

  std::cout << "Before insertion:" << std::endl;
  std::cout << "Names in Dictionary: " << std::endl;

  
}
