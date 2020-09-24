#include<vector>


struct Node{
    Node(int, int);
    int value;
    std::vector<Node> children;
    void addChild(int, int);
    int parent;
};

std::vector<Node> connectNodes(std::vector<Node> nodes);

void inverseTree(Node& root, std::vector<Node> nodeList);