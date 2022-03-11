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
    temp ->setNext(walker);
    trailer->setNext(temp);
  }

}
  
/*
void OList::insert(int value){
  ONode *temp = new ONode(value);

  //a walker to check if the number before it is bigger
  //if smaller, insert value right after

  //if larger, keep going untill we found the number smaller than value

  ONode *walker = head;
}
*/

std::string OList::toString(){
  std::string result = "";
  ONode *walker = this->head;
  while (walker != nullptr){
    result = result + std::to_string(walker->getData()) + "->";
    walker = walker->getNext();
  }

  result = result + "null";
  return result;
}
