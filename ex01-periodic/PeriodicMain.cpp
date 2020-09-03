#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Periodic.h"

using namespace std;
using namespace ds_course;

int main()
{    
    Periodic pal;
    string mode;
    cin >> mode;
    string inputString;
    int inputDec;
    int inputHex;

    //cout << '\'' << mode << '\'' << endl;
    cin.ignore(10000,'\n');

    string inputLine;
    while (getline(cin, inputLine)) {
        istringstream sstr(inputLine);
        if (sstr.peek() == '#') {
            continue;
        }
        else {
            if (mode == "dec") {
                sstr >> inputDec;
                string out = to_string(inputDec);
                int res = pal.isPeriodic(inputDec);
                cout << pal.output << " " << res << endl;
            } else if (mode == "str" || mode == "hex") {
                sstr >> inputString;
                int res = pal.isPeriodic(inputString);
                cout << pal.output << " " << res << endl;
            }
        }
    }
}
