#include <sstream>
#include <iostream>
#include "Alien.h"
#include "Stack.h"
#include "FavouriteRelatives.h"

using namespace std;

FavouriteRelatives inorderDFS(Alien* node, Alien* aliens[]);

int main(){
    Alien* aliens[10001];
    string line;
    while(getline(cin, line)){
        istringstream ss(line);
        char mode;
        ss >> mode;
        cout << mode << "- MODE"<< endl;
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
                FavouriteRelatives answer;
                answer = inorderDFS(aliens[parent_value], aliens);
                cout << answer.previous << " " << answer.next << endl;   
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

FavouriteRelatives inorderDFS(Alien* node, Alien* aliens[]){
    FavouriteRelatives answer;
    Alien* temp = aliens[node->getRootValue()];
    int previous_value;
    Stack<int> stack;
    while(temp || !stack.isEmpty()){
        while(temp){
            stack.push(temp->value);
            temp = temp->left;
        }
        cout << "BRUH" << endl;
        temp = aliens[stack.pop()];
        if(temp->value == node->value){
            answer.previous = previous_value;
        }
        else if(previous_value == node->value){
            answer.next = temp->value;
            return answer;
        }
        previous_value = temp->value;
        temp = temp->right;
    }
    return answer;
}