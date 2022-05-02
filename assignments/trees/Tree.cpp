#include <iostream>
#include "Node.h"
#include "Tree.h"

Tree::Tree(){
  root = nullptr;
}

std::string Tree::recursion(Node *r){
  if (r == nullptr){
    return "";
  }
  else {
    return recursion(r->getLeft()) + ", " + std::to_string(r->getData()) + ", " + recursion(r->getRight());
  }
}

std::string Tree::printTree_Rec(){
  return recursion(root);
}

int Tree::search(int value){
  Node *t = root;
  
  while (t!= nullptr){
    int tval = t->getData();
    if (tval == value){
      return value;
    }
    if (tval < value){
      t = t->getRight();
    }
    else {
      t = t->getLeft();
    }
  }
  //throws if it reaches here but value isnt found
  throw 1;
}

int Tree::rsearch(int value, Node *p){
  if (p == nullptr){
    throw 1;
  }
  
  if (p->getData() == value){
    return value;
  }
  
  if (value < p->getData()){
    return rsearch(value, p->getLeft());
  }
  else{
    return rsearch(value, p->getRight());
  }
}

int Tree::rsearch(int value){
  int v = rsearch(value, root);
  return v;
}

void Tree::insert(int value){
  Node *newnode = new Node(value);
  Node *p = root;
  Node *trailer; 
  while (p != nullptr) {
    trailer = p;
    if (p->getData() == value){
      return;
    }
    else if (p->getData() < value){
      p = p->getRight(); 
    } else {
      p = p->getLeft();
    }
  }
  if (root==nullptr){
    root=newnode;
  } else {
    if (trailer->getData() < value){
      trailer->setRight(newnode);
    } else {
      trailer->setLeft(newnode);
    }
  }
}

void Tree::rinsert(int value, Node *p){
  if (p == nullptr){
    Node *newnode = new Node(value);
    p = newnode;
    return;
  }
  //std::cout << //"checked if null";
  
  if (p->getData() < value){
    //std::cout << //"checked if right";
    return rinsert(value, p->getRight());
  }
  else if (p->getData() > value){
    //std::cout << "checked if left";
    return rinsert(value, p->getLeft());
  }

  //nothing is done if they are equal;
}

void Tree::rinsert(int value){
  if (root == nullptr){
    Node *newnode = new Node(value);
    root = newnode;
  }
  else{
    rinsert(value, root);
  }
}

