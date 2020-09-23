#include<iostream>
#include <string>
#include <sstream>
#include"Node.h"

using namespace std;

int main(){
    static string line;
    vector<Node> nodes;
    getline(cin, line);
    while(line != "0"){
        vector<int> intNodes;
        stringstream ss;
        ss.str(line);
        int num;
        while (ss >> num) {
            intNodes.push_back(num);
        }
        Node Parent(intNodes[0], nullptr);
        for(int i = 1; i < nodes.size(); i++){
            Parent.addChild(intNodes[i]);
        }
        nodes.push_back(Parent);
        getline(cin, line);
    }
    for(int i = 0; i < nodes.size(); i++){
        cout << nodes[i].value << endl;
    }
    return 0;
}
