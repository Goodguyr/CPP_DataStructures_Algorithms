#ifndef NODE_H
#define NODE_H

#include <string>

struct Node{
    Node(std::string value): count(1),
    left(NULL), right(NULL), height(1), word(value){};
    int count;
    std::string word;
    Node* left;
    Node* right;
    int height;
};

#endif