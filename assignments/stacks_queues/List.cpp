#include <iostream>
#include "List.h"

List::List() {
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

void List::insert(int value)
{
    // create a new node
  Node *temp = new Node(value);
  Node *walker = head;
  Node *trailer = nullptr;
  
  while (walker !=nullptr && walker->getData()  < temp->getData()){
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
    result = result + std::to_string(walker->getData()) + "->";
    walker = walker->getNext();
  }

  result = result + "null";
  return result + "\n";
}

bool List::contains(int value){
  Node *temp = new Node(value);

  Node *walker = head;

  while (walker != nullptr){
    if (walker->getData() == temp->getData()){
      return true;
    }
    walker = walker->getNext();
  }
  return false;
}

int List::get(int loc){
  Node *temp = new Node(loc);
  Node *walker = head;

  while (walker !=nullptr and loc > 0){
    walker = walker->getNext();
    loc--;
  }

  if (loc >0){
    throw std::out_of_range("Out of Range");
  }
  else {
    return walker->getData();
  }

}


void List::remove(int loc){
  Node *walker = head;
  Node *trailer = nullptr;

  while (walker != nullptr & loc >0){
    trailer = walker;
    walker= walker->getNext();
    loc--;
  }

  if (trailer == nullptr){
    head = walker->getNext();
    delete walker;
  }
  else {
    trailer->setNext(walker->getNext());
    delete walker;
  }
}

void List::reverse()
{
   Node *walker = head;
   Node *trailer=nullptr; // this one follows behind walker;
    while(walker != nullptr)
    {
      Node *walker2 = walker->getNext();
      walker->setNext(trailer);
      trailer=walker;
      walker=walker2;
    }
    head = trailer;
}
