#include "Circle.h"
#include "Polygon.h"
#include "Shape.cpp"
#include "Stack.h"
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

int main(){
    Stack stack;
    string line;
    Shape* temp;
    while(getline(cin, line)){
        istringstream ss(line);
		string action, color;
		ss >> action;
        if(action == "POLYGON"){
            int sides;
            ss >> color;
            ss >> sides;
            stack.push(new Polygon(sides, color));
        }
        else if(action == "CIRCLE"){
            ss >> color;
            temp = new Circle(color);
            stack.push(temp);
        }
        else if(action == "GROUP"){
            int count;
            ss >> count;
            stack.group(count);
        }
        else if(action == "TRANSF"){
            // string mode;
            // ss >> mode;
            // Shape* temp = stack.pop(); 
            // temp->transform(mode);
            // stack.push(temp);
        }
        else if(action == "SHOW"){
            int width, height;
            ss >> width >> height;
            cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
            cout << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" + to_string(width) + "\" height=\"" + to_string(height) + "\">" << endl;
            Shape* output = stack.pop();
            output->transform("SCA");
            output->show();
            cout << "<rect x=\"0\" y=\"0\" width=\"" + to_string(width) + "\" height=\"" + to_string(height) + "\" stroke=\"#999999\" fill=\"none\" stroke-width=\"1\"/>" << endl;
            cout << "</svg>" << endl;
            return 0;
        }
    }
    return 0;
}