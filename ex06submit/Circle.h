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
            points[i][0] = 0.5 * cos(0.36 * PI * i / 180) + 0.5;
            points[i][1] = 0.5 * sin(0.36 * PI * i / 180) + 0.5;
        }
    };
    void transform(std::string type);
    void show();
    // Shape copy();
};
#endif