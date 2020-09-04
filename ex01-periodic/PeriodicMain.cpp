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
    string input;

    //cout << '\'' << mode << '\'' << endl;
    cin.ignore(10000,'\n');

    string inputLine;
    while (getline(cin, inputLine)) {
        istringstream sstr(inputLine);
        if (sstr.peek() == '#') {
            continue;
        }
        else {
            sstr >> input;
            int res = pal.isPeriodic(input, mode);
            cout << pal.output << " " << res << endl;
        }
    }
}
