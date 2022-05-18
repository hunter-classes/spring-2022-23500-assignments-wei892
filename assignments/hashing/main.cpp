#include <iostream>

int main(){
  Dictionary *clebrities = new Dictionary();

  Person *c1 = new Person("Pitt","Brad", 1);
  Person *c2 = new Person("Johnson","Dwayne", 2);
  Person *c3 = new Person("Perry","Katie",3);
  Person *c4 = new Person("Stone", "Emma", 4);
  Person *c5 = new Person("Depp", "Johnny", 5);

  std::cout << "Before insertion:" << std::endl;
  std::cout << "Names in Dictionary: " << std::endl;
  
  celebrities->insert(c1);
  celebrities->insert(c2);
  celebrities->insert(c3);
  celebrities->insert(c4);
  celebrities->insert(c5);

  std::cout << "\nAfter insertion:" << std::endl;
  std::cout << "Names in Dictionary: " << std::endl;
  celebrities->
  
  return 0;
}
