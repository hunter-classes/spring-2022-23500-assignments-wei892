#include <iostream>
#include "List.h"

List::List(){
  head = nullptr;
  size = 0;
}

List::~List(){
  Node *trailer;
  std::cerr << "Destructing\n";
  while (head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}

void List::insert(Person *p){
  Node *temp = new Node(p);
  Node *walker = head;
  Node *trailer = nullptr;

  while (walker !=nullptr && walker->getPerson()  < temp->getPerson()){
    trailer = walker;
    walker = walker->getNext();
    }

    if (trailer == nullptr){
    temp->setNext(head);
    head = temp;
  }
  else{
    temp->setNext(walker);
    trailer->setNext(temp);
  }
}

std::string List::toString(){
  std::string result = "";
  Node *walker = this->head;
  while (walker != nullptr){
    result = result + walker->getPerson()->get_name() + "->";
    walker = walker->getNext();
  }

  result = result + "null";
  return result + "\n";
}

