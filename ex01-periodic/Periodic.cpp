#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Periodic.h"

using namespace ds_course;
using namespace std;

int longestPeriod(vector<char>);

Periodic::Periodic() {

}

int Periodic::isPeriodic(int number){
    int length;
    vector<char> line;
    while(number){
        length += 1;
        int temp = number % 10;
        char n = '0' + temp;
        line.push_back(n);
        number = number / 10;
    }
    reverse(line.begin(), line.end());
    return longestPeriod(line);
}


int Periodic::isPeriodic(string word) {
    vector<char> line;
    copy(word.begin(), word.end(), back_inserter(line));
    return longestPeriod(line);
}


int longestPeriod(vector<char> line){
    bool odd;
    int lineLength = line.size() - 1;
    cout << "Input length: " << line.size() << endl;
    int sep = lineLength + 1;
    vector<string> periods;
    string LHS, RHS, sample, fullLine, answer;
    
    if(sep & 1){
        odd = true;
        sep = lineLength + 1;
        sep /= 2;
    }
    else{
        sep /= 2;
    }

    for(int i = 0; i < sep; i++){
        LHS += line[i];
        RHS.insert(0, 1, line[lineLength - i]);
        if(LHS == RHS){
            cout << LHS << "   " << RHS << endl;
            periods.push_back(LHS);
        }
    }

    fullLine = LHS + RHS;

    if(odd){
        fullLine.insert(sep, 1, line[sep]);
    }

    if(!periods.size()){
        return 0;
    }
    else{
        for(string period : periods){
            cout << period << endl;
            if (!(line.size() % period.size())){
                int times = line.size() / period.size();
                for(int i = 0; i < times; i++){
                    sample += period;
                }
                cout << "sample is " << sample << endl;
                cout << "full line is " << fullLine << endl;
                if(sample == fullLine){
                    answer = period;
                    break;
                }
            }
        }
    return answer.size();
    }
}
