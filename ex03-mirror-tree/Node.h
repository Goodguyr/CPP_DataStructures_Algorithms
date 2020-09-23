#include<vector>


struct Node{
    Node(int, Node*);
    ~Node();
    int value;
    std::vector<Node> children;
    void addChild(int);
    Node* parent;
};

void inverseTree(Node* root);