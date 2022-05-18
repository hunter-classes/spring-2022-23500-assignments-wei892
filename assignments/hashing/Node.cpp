#include <iostream>
#include "Node.h"
#include "Person.h"

Node::Node() : next(nullptr)
{
}

Node::Node(Person *p){
  person = p;
  this->next = nullptr;
}

Node::Node(Person *p, Node *next){
  person = p;
  this->next = next;
}

void Node::setPerson(Person *p){
  person  = p;
}

void Node::setNext(Node *next){
  this->next = next;
}

Person* Node::getPerson(){
  return person;
}

Node *Node::getNext(){
  return this->next;
}


