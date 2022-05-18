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

void List::insert(int loc, Person *p){
  Node *tmp = new Node(p);

  Node *walker = head;
  Node *trailer=nullptr; // this one follows behind walker;
  
  while (walker != nullptr && loc > 0){
    trailer = walker;
    walker = walker->getNext();
    loc--;
  }
    if (loc > 0){
    throw std::out_of_range("Out of range");
  }
  if (trailer==nullptr){
    tmp->setNext(head);
    head=tmp;
  } else {
    tmp->setNext(walker);
    trailer->setNext(tmp);
  }
}

bool List::contains(Person *p){
  Node *temp = new Node(p);

  Node *walker = head;

  while (walker != nullptr){
    if (walker->getPerson() == temp->getPerson()){
      return true;
    }
    walker = walker->getNext();
  }
  return false;
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

Person* List::get(std::string name){
  Node *walker = head;

  while (walker !=nullptr && walker->getPerson()->get_name() != name){
    walker = walker->getNext();
  }

  if (walker == nullptr){
    return nullptr;
  }
  else {
    return walker->getPerson();
  }
}

int List::length(){
  int l = 0;
  Node *walker = head;
  while (walker){
    l++;
    walker = walker->getNext();
  }
  return l;
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

