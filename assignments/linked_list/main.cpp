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

  
  return 0;
}
