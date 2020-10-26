#ifndef GROUP_H
#define GROUP_H
#include "Shape.cpp"
#include <vector>
#include <sstream>
#include <iostream>

class Group : public Shape {
public:
    std::vector<Shape*> shapes;
    Group(){};
    Group(const Group& n){
        for(int i = 0; i < n.shapes.size(); i++){
            Shape* temp = n.shapes[i];
            temp = temp->copy();
            shapes.push_back(temp);
        }
    };
    void transform(std::string type, std::istringstream& ss){
        for(int i = 0; i < shapes.size(); i++){
            std::istringstream ss2(ss.str());
            std::string waste;
            ss2 >> waste;
            ss2 >> waste;
            shapes[i]->transform(type, ss2);
        }
    };
    void show(){
        for(int i = shapes.size() - 1; i >= 0; i--){
            shapes[i]->show();
        }
    };
    Shape* copy(){
        Shape* newShape = new Group(*this);
        return newShape;
    };
};
#endif