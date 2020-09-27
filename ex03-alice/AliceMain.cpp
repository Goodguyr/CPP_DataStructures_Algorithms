#include<iostream>
#include <string>
#include <sstream>
#include<map>
#include"Node.h"

using namespace std;

int main(){
    map<int, Node*> valNodes;
    map<int, int> childToParent;
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
        Node Parent(intNodes[0]);
        for(int i = 1; i < intNodes.size(); i++){
            Parent.addChild(intNodes[i]);
            childToParent[intNodes[i]] = intNodes[i];
        }
        nodes.push_back(Parent);
        getline(cin, line);
    }

    Node* root;
    for(int i = 0; i < nodes.size(); i++){
        if(!childToParent.count(nodes[i].value)){
            root = &nodes[i];
        }
        valNodes[nodes[i].value] = &nodes[i];
    }

    inverseTree(root, &valNodes);
    cout << 0;
    return 0;
}
