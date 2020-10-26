#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.cpp"
#include<string>
#include<cmath>


#define PI 3.14

class Circle : public Shape{
    double points[1000][2];
public:
    Circle(std::string color): Shape(1000, color){
        for(int i = 0; i < sides; i++){
            points[i][0] = cos(0.36 * PI * i / 180);
            points[i][1] = sin(0.36 * PI * i / 180);
        }
    };
    Circle(const Circle& n): Shape(1000, n.color) {
        for(int i = 0; i < sides; i++){
            points[i][0] = n.points[i][0];
            points[i][1] = n.points[i][1];
        }
    }
    void transform(std::string type,std::istringstream& ss);
    void show();
    Shape* copy(){
        Shape* newShape = new Circle(*this);
        return newShape;
    };
};
#endif