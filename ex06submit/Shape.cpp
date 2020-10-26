#ifndef SHAPECPP
#define SHAPECPP
#include <string>
#include <sstream>

class Shape{
public:
    std::string color;
    int sides;
    Shape(int sides_t = 1000, std::string c = "FFFFFF"): color(c), sides(sides_t){};
    virtual void transform(std::string type, std::istringstream& ss) = 0;
    virtual void show() = 0;
};

#endif