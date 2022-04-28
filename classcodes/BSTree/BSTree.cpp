#include <iostream>
#include "Node.h"
#include "BSTree.h"


BSTree::BSTree(){
  root = nullptr;
}

void BSTree::insert(int d){

}

std::string BSTree::get_debug_string(){
  if (root == nullptr){
    return "";
  }
  else {
    return std::to_string(root->getData()) + " " + std::to_string(root->getLeft()->getData());
  }
}

std::string BSTree::traverse(Node *r){
  std::string a,b,c;
  if (r == nullptr){
    return "";
  }
  else{
    return traverse(r->getLeft()) + ", " + std::to_string(r->getData()) + ", " + traverse(r->getRight());
    return a + ", " + b+ ", " + c;

    
  }
}

std::string BSTree::get_debugger_Rec(){
  return traverse(root);
}

void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setLeft(n);
  n = new Node(30);
  root->setRight(n);
  n = new Node(40);
  root->getLeft()->setLeft(n);
  
}


