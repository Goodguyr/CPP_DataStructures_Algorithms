#include<vector>
#include "Node.h"

using namespace std;

Node::Node(int val, Node* parent = nullptr){
    this->value = val;
    this->parent = parent;
}

Node::~Node(){
    delete this->parent;
}

void Node::addChild(int val){
    this->children.push_back(Node(val, this));
}

void inverseTree(Node* root){

}