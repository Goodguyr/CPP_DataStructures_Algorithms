#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "node.h"

extern int startDeleting;
extern int endDeleting;

class AVLTree{
public:
    Node* root;
    int (*compareFunction)(std::string, std::string);
    int height(Node*);
    int getBalanceFactor(Node*);
    Node* rr_rotation(Node*);
    Node* ll_rotation(Node*);
    Node* lr_rotation(Node*);
    Node* rl_rotation(Node*);
    Node*  balance(Node*);
    Node* insert(Node*, std::string);
    Node* deleteNode(Node*, std::string);
    void locate(Node*, std::string);
    void get(Node*, std::string);
    void dump(Node*, std::string, std::string);
    AVLTree(){
        root = NULL;
    }
};

bool isUpper(char n);
int lexicographicalCompare(std::string word, std::string otherWord);
int shortlexCompare(std::string word, std::string otherWord);
int colexCompare(std::string word, std::string otherWord);

#endif