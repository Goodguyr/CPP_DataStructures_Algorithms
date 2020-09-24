#include<vector>
#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int val, int par){
    value = val;
    parent = par;
}

void Node::addChild(int val, int par){
    children.push_back(Node(val, par));
}

vector<Node> connectNodes(vector<Node> nodes){
    int noParent = 0;
    while(noParent != 1){
        noParent = 0;
        for(int i = 0; i < nodes.size(); i++){
            if(nodes[i].parent == 0){
                noParent++;
                for(int j = 0; j < nodes.size(); j++){
                    for(int k = 0; k < nodes[j].children.size(); k++){
                        if(nodes[j].children[k].value == nodes[i].value){
                            nodes[i].parent = nodes[j].value;
                        }
                    }
                }
            }
        }
    }
    return nodes;
}


void inverseTree(Node& node, vector<Node> nodeList){
    string line = "";
    line += to_string(node.value);
    int i = node.children.size();
    vector<Node> hasChildren;
    while(i != 0){
        i--;
        line += " ";
        line += to_string(node.children[i].value);
        Node* child;
        for(Node oneNode : nodeList){
            if(oneNode.value == node.children[i].value && oneNode.children.size()){
                hasChildren.push_back(oneNode);
            }
        }
    }
    cout << line << endl;
    for(Node i : hasChildren){
        //Node child = node.children[i];
        inverseTree(i, nodeList);
    }
}
