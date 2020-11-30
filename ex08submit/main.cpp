#include <iostream>
#include <sstream>
#include "AVLtree.h"

using namespace std;

int main(){
    string line, mode;
    AVLTree myTree;
    myTree.root = NULL;
    int lineCounter = 1;
    cin >> mode;
    if(mode == "COLEX"){
        myTree.compareFunction = colexCompare;
    }
    else if(mode == "LEX"){
        myTree.compareFunction = lexicographicalCompare;
    }
    else if(mode == "SHORTLEX"){
        myTree.compareFunction = shortlexCompare;
    }
    cin.ignore();
    while(getline(cin, line)){
        lineCounter++;
        string word;
        istringstream lineInputStream(line);
        char action;
        lineInputStream >> action;
        if(action == 'I'){
            while(lineInputStream >> word){
                myTree.root = myTree.insert(myTree.root, word);
            }
        }
        if(action == 'E'){
            while(lineInputStream >> word){
                myTree.root = myTree.deleteNode(myTree.root, word);
            }
        }
        if(action == 'G'){
            lineInputStream >> word;
            cout << lineCounter << " ";
            myTree.get(myTree.root, word);
        }
        if(action == 'L'){
            lineInputStream >> word;
            cout << lineCounter << " ";
            myTree.locate(myTree.root, word);
        }
        if(action == 'D'){
            string end;
            lineInputStream >> word;
            lineInputStream >> end;
            cout << lineCounter << " ";
            startDeleting = 0;
            endDeleting = 0;
            myTree.dump(myTree.root, word, end);
            cout << endl;
        }
        if(action == 'F'){
            break;
        }
    }
    return 0;
}
