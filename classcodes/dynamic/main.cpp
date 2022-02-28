#include <iostream>
#include "Node.h"

int main(int argc, char *argv[])
{
  Node *p1 = new Node();
  p1->setData("Hello"); //create a variable that will point to a node that contains the hello value

  Node *p2 = new Node("World");
  p1->setNext(p2);

  std::cout << p1->getData() << std::endl;
  std::cout << p2->getData() << std::endl;
  std::cout << p1->getNext()->getData() << std::endl; //getNext() will give p2, and using getData will give the data for p2

  p2 = new Node("!");
  p1->getNext()->setNext(p2);

  std::cout << p1->getData() << std::endl;
  std::cout << p1->getNext()->getData() << std::endl;
  std::cout << p1->getNext()->getNext()->getData() << std::endl;
  
  Node *walker = p1;
  std::cout << walker->getData() << "\n";
  walker = p1->getNext(); //you can also write walker = walker->getNext() since walker is p1
  std::cout << walker->getData() << "\n";

  walker = walker->getNext(); 
  std::cout << walker->getData() << "\n";

  walker = p1;
  while (walker != nullptr){
    std::cout << walker->getData() << "\n";
    walker = walker->getNext();//walker = p1->getNext();
  }
  return 0;
}
