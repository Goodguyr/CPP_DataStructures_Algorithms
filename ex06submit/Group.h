#ifndef GROUP_H
#define GROUP_H
#include "Shape.cpp"
#include <vector>

class Group : public Shape {
public:
    std::vector<Shape*> shapes;
    Group(){};
    void transform(std::string type){
        for(int i = 0; i < shapes.size(); i++){
            shapes[i]->transform(type);
        }
    };
    void show(){
        for(int i = 0; i < shapes.size(); i++){
            shapes[i]->show();
        }
    };
};
#endif