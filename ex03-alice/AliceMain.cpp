#include<iostream>
#include <string>
#include <sstream>
#include"Node.h"

using namespace std;

int main(){
    string line;
    vector<Node> nodes;
    getline(cin, line);
    while(line[0] != '0'){
        vector<int> intNodes;
        istringstream ss(line);
        int num;
        while (ss >> num) {
            intNodes.push_back(num);
        }
        Node Parent(intNodes[0], 0);
        for(int i = 1; i < intNodes.size(); i++){
            Parent.addChild(intNodes[i], Parent.value);
        }
        nodes.push_back(Parent);
        getline(cin, line);
    }
    nodes = connectNodes(nodes);

    for(Node node: nodes){
        if(!node.parent){
            inverseTree(node, nodes);
        }
    }
    cout << 0;
    return 0;
}
