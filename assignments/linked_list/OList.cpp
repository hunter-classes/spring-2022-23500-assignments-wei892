#include <iostream>
#include "OList.h"

/*
constructor
  OList();
  //destructor
  ~OList();

  //insert a new node with value in its proper location
  void insert(int value);
  //returns a string presentation of the full list
  std::string toString();
  //retruns true if value is in the list, false otherwise
  bool contains(int value);
  //returns the value at location
  int get(loc);
  //returns the value at loc
  void remove(loc);
  //reverse the pointers
  void reverse();
 */


OList::OList() {
  head = nullptr;
  size = 0;
}

OList::~OList(){
  ONode *trailer;
  std::cerr << "Destructing\n";
  while (head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}

void OList::insert(int value)
{
    // create a new node
  ONode *temp = new ONode(value);
  ONode *walker = head;
  ONode *trailer = nullptr;
  
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

std::string OList::toString(){
  std::string result = "";
  ONode *walker = this->head;
  while (walker != nullptr){
    result = result + std::to_string(walker->getData()) + "->";
    walker = walker->getNext();
  }

  result = result + "null";
  return result + "\n";
}

bool OList::contains(int value){
  ONode *temp = new ONode(value);

  ONode *walker = head;

  while (walker != nullptr){
    if (walker->getData() == temp->getData()){
      return true;
    }
    walker = walker->getNext();
  }
  return false;
}

int OList::get(int loc){
  ONode *temp = new ONode(loc);

  ONode *walker = head;

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


void OList::remove(int loc){
  ONode *walker = head;
  ONode *trailer = nullptr;

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

void OList::reverse()
{
   ONode *walker = head;
   ONode *trailer=nullptr; // this one follows behind walker;
    while(walker != nullptr)
    {
      ONode *walker2 = walker->getNext();
      walker->setNext(trailer);
      trailer=walker;
      walker=walker2;
    }
    head = trailer;
}
