#ifndef STACK_H
#define STACK_H
#include "Shape.cpp"
#include "Group.h"
#include <vector>
#include <iostream>

class Stack{
    int size;
    int pointer;
    std::vector<Shape*> data;
public:
    Stack(){
        size = 0;
        pointer = 0;
    };
    void push(Shape* shape){
        size++;
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
        size--;
        return temp;
    };
};
#endif