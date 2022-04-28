#include <iostream>
#include "Node.h"
#include "BSTree.h"

int main(){
  //=====Video 2====//
  /*
  Node *n = new Node(20);
  std::cout << n->getData() << std::endl;
  Node *n2 = new Node(30);
  n->setLeft(n2);
  n2 = new Node(40);
  n->setRight(n2);

  std::cout << n->getLeft()->getData() << std::endl;
  std::cout << n->getRight()->getData() << std::endl;
  */

  //======Video 4 activity=====//
  BSTree *t = new BSTree();
  t->setup();
  std::cout << t->get_debugger_Rec() << std::endl;

  //std::cout << t->get_debug_string() << std::endl;
  return 0;
}
