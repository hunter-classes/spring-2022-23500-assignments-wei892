#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"

TEST_CASE("Testing dictionary.cpp"){
  Dictionary *celebrities = new Dictionary();

  Person *c1 = new Person("Pitt","Brad", 1);
  Person *c2 = new Person("Johnson","Dwayne", 2);
  Person *c3 = new Person("Perry","Katie",3);
  Person *c4 = new Person("Stone", "Emma", 4);
  Person *c5 = new Person("Depp", "Johnny", 5);

  celebrities->insertPerson(c1);
  celebrities->insertPerson(c2);
  celebrities->insertPerson(c3);
  celebrities->insertPerson(c4);
  celebrities->insertPerson(c5);

  std::string s1 = celebrities->retrievePerson(c2)->get_name();
  CHECK(s1 == "Dwayne, Johnson");
  s1 = celebrities->retrievePerson(c5)->get_name();
  CHECK(s1  == "Johnny, Depp");

  CHECK(celebrities->retrievePerson(c3) == c3);

}
