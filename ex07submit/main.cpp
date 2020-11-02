#include <sstream>
#include <iostream>
#include "Alien.h"
#include "Stack.h"

using namespace std;

void get_fav_relatives(Alien* node, Alien** aliens);
void DFS(Alien* node, Stack<int>* stack, int initial_val);

int main(){
    Alien* aliens[10001];
    string line;
    while(getline(cin, line)){
        istringstream ss(line);
        char mode;
        ss >> mode;
        int parent_value, child_value;
        if(mode == 'T'){
            ss >> parent_value;
            if(!aliens[parent_value]){
                aliens[parent_value] = new Alien(parent_value);
            }
            else{
                cout << "error6" << endl;
            }
        }
        else if(mode == 'L' || mode == 'R'){
            ss >> parent_value >> child_value;
            if(parent_value == child_value){
                cout << "error1" << endl;
            }
            else if(!aliens[parent_value]){
                cout << "error2" << endl;
            }
            else if(aliens[child_value]){
                cout << "error3" << endl;
            }
            else if(aliens[parent_value]->left && mode == 'L'){
                cout << "error4" << endl;
            }
            else if(aliens[parent_value]->right && mode == 'R'){
                cout << "error5" << endl;
            }
            else{
                aliens[child_value] = new Alien(child_value);
                aliens[child_value]->parent = aliens[parent_value];
                if(mode == 'L'){
                    aliens[parent_value]->left = aliens[child_value];
                }
                else{
                    aliens[parent_value]->right = aliens[child_value];
                }
            }
        }
        else if(mode == '?'){
            ss >> parent_value;
            if(aliens[parent_value]){
                get_fav_relatives(aliens[parent_value], aliens);
            }
            else{
                cout << "error0" << endl;
            }
        }
        else if(mode == 'F'){
            return 0;
        }
    }
    return 0;
}

void get_fav_relatives(Alien* node, Alien** aliens){
    Alien* root = node->getRootNode();
    int prev, next;
    Stack<int> stack;
    DFS(root, &stack, node->value);
    next = stack.pop();
    if(next == node->value){
        cout << stack.pop() << " " << 0 << endl;
        return;
    }
    while(stack.peek() != node->value){
        next = stack.pop();
    }
    stack.pop();
    prev = stack.pop();
    cout << prev << " " << next << endl;
}

void DFS(Alien* node, Stack<int>* stack, int initial_val){
    if(!node){return;}
    DFS(node->left, stack, initial_val);
    stack->push(node->value);
    DFS(node->right, stack, initial_val);
}