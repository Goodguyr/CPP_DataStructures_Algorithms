#include "Circle.h"
#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

#define PI 3.14

void Circle::show(){
    std::string answer = "<path d=";
    answer.append("\"M " + std::to_string(this->points[0][0]) + " " + std::to_string(this->points[0][1]));
    for(int i = 1; i < sides; i++){
        answer.append(" L " + std::to_string(this->points[i][0]) + " " + std::to_string(this->points[i][1]));
    }
    answer.append("\" fill=\"" + color + "\"/>\n");
    std::cout << answer;
}

void Circle::transform(std::string type, std::istringstream& ss){
    double dx, dy;
    ss >> dx;
    if(type == "TRA"){
        ss >> dy;
        for(int i = 0; i < sides; i++){
            Matrix<double> original(3,1);
            original.addNumber(points[i][0]);
            original.addNumber(points[i][1]);
            original.addNumber(1);
            Matrix<double> translate;
            translate.getNum(0,2) = dx;
            translate.getNum(1,2) = dy;
            original = translate * original;
            points[i][0] = original.getNum(0,0);
            points[i][1] = original.getNum(1,0);
        }
    }
    else if(type == "ROT"){
        for(int i = 0; i < sides; i++){
            Matrix<double> original(3,1);
            original.addNumber(points[i][0]);
            original.addNumber(points[i][1]);
            original.addNumber(1);
            Matrix<double> translate;
            translate.getNum(0,0) = cos(dx * PI / 180);
            translate.getNum(1,1) = cos(dx * PI / 180);
            translate.getNum(1,0) = sin(dx * PI / 180);
            translate.getNum(0,1) = -sin(dx * PI / 180);
            original = translate * original;
            points[i][0] = original.getNum(0,0);
            points[i][1] = original.getNum(1,0);
        }
    }
    else if(type == "SCA"){
        ss >> dy;
        for(int i = 0; i < sides; i++){
            Matrix<double> original(3,1);
            original.addNumber(points[i][0]);
            original.addNumber(points[i][1]);
            original.addNumber(1);
            Matrix<double> translate;
            translate.getNum(0,0) = dx;
            translate.getNum(1,1) = dy;
            original = translate * original;
            points[i][0] = original.getNum(0,0);
            points[i][1] = original.getNum(1,0);
        }
    }
    else if(type == "SHE"){
        ss >> dy;
        for(int i = 0; i < sides; i++){
            Matrix<double> original(3,1);
            original.addNumber(points[i][0]);
            original.addNumber(points[i][1]);
            original.addNumber(1);
            Matrix<double> translate;
            translate.getNum(0,1) = dx;
            translate.getNum(1,0) = dy;
            original = translate * original;
            points[i][0] = original.getNum(0,0);
            points[i][1] = original.getNum(1,0);
        }
    }
}