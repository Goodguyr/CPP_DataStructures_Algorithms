#ifndef STACK_H
#define STACK_H
#include "Shape.cpp"
#include "Group.h"
#include <vector>
#include <iostream>

class Stack{
    std::vector<Shape*> data;
public:
    Stack(){};
    void push(Shape* shape){
        data.push_back(shape);
    };
    void group(int n){
        Group* newGroup = new Group();
        for(int i = 0; i < n; i++){
            newGroup->shapes.push_back(pop());
        }
        data.push_back(newGroup);
    };
    Shape* pop(){
        Shape* temp = data.back();
        //pop back might destroy
        data.pop_back();
        return temp;
    };
};
#endif