#include<vector>
#include <iostream>
#include<map>
#include "Node.h"

using namespace std;

Node::Node(int val){
    value = val;
}

void Node::addChild(int val){
    children.push_back(val);
}

void inverseTree(Node* node, map<int, Node*>* nodeList){
    string line = "";
    line += to_string(node->value);
    vector<Node*> hasChildren;
    for(int i = node->children.size() - 1; i > -1; i--){
        line += " ";
        line += to_string(node->children[i]);
        if(nodeList->count(node->children[i])){
            hasChildren.push_back(nodeList->operator[](node->children[i]));
        }
    }
    cout << line << endl;
    for(Node* i : hasChildren){
        inverseTree(i, nodeList);
    }
}
