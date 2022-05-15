#include <iostream>
#include "Node.h"
#include "Tree.h"
#include <time.h>

int main(){
  /*
  rand(time(NULL));
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
  */
  Tree *t = new Tree();
  t->setup();

  std::cout << t->printTree_Rec() << std::endl;
  std::cout << "Counting Leaves in Tree t: " << t->countLeaves() << std::endl;
  t->deleteNode(19);
  std::cout << t->printTree_Rec() << std::endl;
  std::cout << "Counting Leaves in Tree t: " << t->countLeaves() << std::endl;
  t->deleteNode(37);
  std::cout << t->printTree_Rec() << std::endl;
  std::cout << "Counting Leaves in Tree t: " << t->countLeaves() << std::endl;
  t->deleteNode(75);
  std::cout << t->printTree_Rec() << std::endl;
  std::cout << "Counting Leaves in Tree t: " << t->countLeaves() << std::endl;

  std::cout << "Finding height of Tree t: " << t->findHeight() << std::endl;
  std::cout << "Finding sum of level 0: " << t->sum(0) << std::endl;
  std::cout << "Finding sum of level 1: " << t->sum(1) << std::endl;
  std::cout << "Finding sum of level 2: " << t->sum(2) << std::endl;
}
