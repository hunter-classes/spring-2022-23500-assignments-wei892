#include <iostream>
#include "Node.h"

int main(){

  Node *n = new Node(20);
  std::cout << n->getData() << std::endl;
  Node *n2 = new Node(30);
  n->setLeft(n2);
  n2 = new Node(40);
  n->setRight(n2);

  std::cout << n->getLeft()->getData() << std::endl;
  std::cout << n->getRight()->getData() << std::endl;
  return 0;
}
