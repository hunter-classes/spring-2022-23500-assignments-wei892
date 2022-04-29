#include <iostream>
#include "Node.h"
#include "BSTree.h"
#include <string>

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

std::string BSTree::recursion(Node *r){
  std::string a,b,c;
  if (r == nullptr){
    return "";
  }
  else{
    return recursion(r->getLeft()) + "," + std::to_string(r->getData()) + ", " + recursion(r->getRight());
    //return a + ", " + b+ ", " + c;

    
  }
}

std::string BSTree::get_debugger_Rec(){
  return recursion(root);
}

void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(7);
  n2->setRight(n);


  /*
  root->setLeft(n);
  n = new Node(20);
  root->setRight(n);
  n = new Node(40);
  root->getLeft()->setLeft(n);  
  */
}



int BSTree::search(int value){
  Node *t = root;

  while (t != nullptr){
    int tval = t->getData();
    if (tval==value){
      // here we'd really return a full object
      // with all the stuff associated with value
      // not just an int
      return value;
    }

    if (tval < value){
      t = t->getRight();
    } else {
      t = t->getLeft();
    }

  }

  // if we get here then the value isn't
  // in the tree

  // normally, if we had a tree of objects
  // we could return null but since we only have
  // an int, we can't return an int to represent
  // not found so we'll throw an exception

  throw 1; // we should define our exceptions.



}

// we will always insert new nodes as leaves
void BSTree::insertNew(int value){

  // make a new node
  Node *newnode = new Node(value);

  // search for where the node would go as a leaf
  // that is, search until we get to null
  // we can use the piggyback strategy of having
  // a second pointer trail the lead pointer
  Node *p = root;
  Node *trailer;


  while (p != nullptr) {
    // note that trailer is one level behind
    trailer = p;

    if (p->getData() < value){
      p = p->getRight();
    } else {
      p = p->getLeft();
    }
  }

  // handle the special case of the tree
  // being empty (null)
  if (root==nullptr){
    root=newnode;
  } else {
    // trailer points to the node ABOVE where the new node
    // will go.
    // we have to figure out if newnode goes on the
    // left of trailer or on the right of trailer
    if (trailer->getData() < value){
      trailer->setRight(newnode);
    } else {
      trailer->setLeft(newnode);
    }

  }
}
