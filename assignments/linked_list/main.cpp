#include <iostream>

#include "Node.h"
#include "List.h"
#include "OList.h"

int main(int argc, char *argv[]){
  OList *O1 =  new OList();

  O1->insert(8);
  O1->insert(9);
  O1->insert(7);
  O1->insert(10);
  O1->insert(6);
  std::cout << O1->toString();

  std::cout << O1->contains(8) << std::endl;

  std::cout << O1->get(3) <<std::endl;

  O1->remove(3);
  std::cout << O1->toString();

  O1->reverse();
  std::cout << O1->toString();
  
  return 0;
}
