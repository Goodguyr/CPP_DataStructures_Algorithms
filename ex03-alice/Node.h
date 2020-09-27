#include<vector>


struct Node{
    Node(int);
    int value;
    std::vector<int> children;
    void addChild(int);
};

void inverseTree(Node* node, std::map<int, Node*>* nodeList);