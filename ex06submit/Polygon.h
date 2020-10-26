#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.cpp"
#include <string>
#include <cmath>

#define PI 3.14

class Polygon : public Shape {
public:
    double **points;
    Polygon(int n, std::string col) : Shape(n,col){
        points = new double*[n];
        for(int i = 0; i < sides; i++){
            points[i] = new double[2];
            points[i][0] = cos(360 / sides * PI * i / 180);
            points[i][1] = sin(360 / sides * PI * i / 180);
        }
    };
    // ~Polygon(){
    //     for(int i = 0; i < sides; i++){
    //         delete points[i];
    //     }
    // }
    void transform(std::string type,std::istringstream& ss);
    void show();
    // Polygon copy();
};
#endif