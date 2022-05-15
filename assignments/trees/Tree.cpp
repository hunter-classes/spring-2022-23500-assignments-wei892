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

int Tree::treeSum(Node *n){
  if (n = nullptr){
    return 0;
  }
  else{
    return n->getData() +
      treeSum(n->getLeft()) +
      treeSum(n->getRight());
  }
}

int Tree::treeSum(){
  return treeSum(root);
}



int Tree::numChild(Node *r){
  int count = 0;
  if (r->getLeft() != nullptr){
    count++;
  }
  if (r->getRight() != nullptr){
    count++;
  }
  return count;
}

void Tree::deleteNode(int n){
  //declare walker and trailer
  Node *walker = root;
  Node *trailer;
  std::string walkerLoc = "";
  Node *temp;
  //search with walker
  while (walker != nullptr){
    if (walker->getData() == n){
      break;
    }
    else if (walker->getData() < n){
      trailer = walker;
      walker = walker->getRight();
      walkerLoc = "right";
    }
    else{
      trailer = walker;
      walker = walker->getLeft();
      walkerLoc = "left";
    }
  }  
  
  //conditions
  int children = numChild(walker);
  
  if (children == 0){
    // walker has no children, is a leaf

    //checking the location of walker
    if (walkerLoc == "right"){
      trailer->setRight(nullptr);
    }
    else {
      trailer->setLeft(nullptr);
    }

    walker = nullptr;
    delete walker;
    return;
  }

  
  else if (children == 1){
    if (walker->getLeft() != nullptr){
      //delete left side

      //checking which side the walker is on in relation to trailer
      if (walkerLoc == "left"){
	trailer->setLeft(walker->getLeft()); 
      }
      else {
	trailer->setRight(walker->getLeft());
      }
    }
    else {
        if (walkerLoc == "right"){
	trailer->setRight(walker->getRight()); 
      }
      else {
	trailer->setLeft(walker->getRight());
      }
    }

    walker = nullptr;
    delete walker;
    return;
  }
  else {
    temp = walker->getLeft();
    //find the next smallest value just before the node that is being deleted

    while(temp->getRight() != nullptr){
      temp = temp->getRight();   
    }
    
    if (walkerLoc == "left"){
      int val = temp->getData();
      deleteNode(temp->getData());
      //trailer->getLeft()->setData(temp->getData());
      walker->setData(val);
    }
    else {
      /*
      trailer->getRight()->setData(temp->getData());
      temp = nullptr;
      delete temp;*/
      int val = temp->getData();
      deleteNode(temp->getData());
      walker->setData(val);
    }
    
    temp = nullptr;
    delete temp;
    }  
}

void Tree::setup(){
  Node *n = new Node (50);
  root = n;
  insert(25);
  insert(75);
  insert(13);
  insert(37);
  insert(63);
  insert(87);
  insert(7);
  insert(19);
  insert(31);
  //insert(43);
  insert(57);
  insert(69);
  insert(81);
  insert(93);
  insert(2);
}


int Tree::countLeaves(Node *r){
  if (r == nullptr){
    return 0;
  }
  else if (isLeaf(r) == true){
    return 1;
  }
  else {
    return countLeaves(r->getLeft()) + countLeaves(r->getRight());
  }
}

int Tree::countLeaves(){
  return countLeaves(root);
}


//check if leaf

bool Tree::isLeaf(Node *r){
  int n = numChild(r);
  if (n==0)
    return true;
  else
    return false;
}

int Tree::findHeight(Node *r){
  if (r == nullptr){
    return 0;
  }
  else if (numChild(r) == 0){
    return 1;
  }
  else {
    int heightLeft = findHeight(r->getLeft());
    int heightRight = findHeight(r->getRight());
    if (heightLeft > heightRight) {
      return findHeight(r->getLeft()) + 1;
    }
    else {
      return findHeight(r->getRight()) + 1;
    }
  }
}

int Tree::findHeight(){
  return findHeight(root);
}
