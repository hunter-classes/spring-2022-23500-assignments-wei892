#include <iostream>
#include "Node.h"

int main(){
  Node *n1 = new Node(10);
  std::cout << "      " << n1->getData() << "\n";

  Node *n2 = new Node(20);
  n1->setLeft(n2);
  n2 = new Node(50);
  n1->setRight(n2);
  std::cout << n1->getLeft()->getData() << "\t    " << n1->getRight()->getData() << std::endl;
  n2 = new Node(30);
  n1->getLeft()->setLeft(n2);
  std::cout << n1->getLeft()->getLeft()->getData();

  n2 = new Node(60);
  n1->getRight()->setLeft(n2);
  n2 = new Node(70);
  n1->getRight()->setRight(n2);
  std::cout << "\t" << n1->getRight()->getLeft()->getData() << " \t" << n1->getRight()->getRight()->getData() << std::endl;

  n2 = new Node(40);
  n1->getLeft()->getLeft()->setLeft(n2);
  std::cout << n1->getLeft()->getLeft()->getLeft()->getData() << std::endl;
  
  
  return 0;
}
