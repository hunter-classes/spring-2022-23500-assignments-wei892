#include <iostream>
#include "Node.h"
#include "Tree.h"
#include <time.h>

int main(){
  srand(time(NULL));
  Tree *t = new Tree();
  int counter = 10;
  while (counter > 0){
    t->insert(rand() % 100 +1);
    counter--;
  }
  
  std::cout << t->printTree_Rec() << std::endl;
  //std::cout << "printed";
  int v = 15;
  
  try {
    int x  = t->search(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";
    
  }

  t->insert(10);
  std::cout << t->printTree_Rec() << std::endl;
  return 0;
}
