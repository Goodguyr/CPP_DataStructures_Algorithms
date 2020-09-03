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
    vector<char> line;
    while(number){
        int temp = number % 10;
        char n = '0' + temp;
        line.push_back(n);
        number = number / 10;
    }
    reverse(line.begin(), line.end());
    while(line[line.size() - 1] == '0'){
        line.erase(line.end() - 1);
    }
    this->output = "";
    for (char i : line){
        this->output += i;
    }
    return longestPeriod(line);
}


int Periodic::isPeriodic(string word) {
    vector<char> line;
    copy(word.begin(), word.end(), back_inserter(line));
    while(line[0] == '0'){
        line.erase(line.begin());
    }
    while(line[line.size() - 1] == '0'){
        line.erase(line.end() - 1);
    }
    for(int i = 0; i < line.size(); i++){
        int temp = line[i];
        if (temp > 64 && temp < 91){
            temp += 32;
            line[i] = (char)temp;
        }
    }
    this->output = "";
    for (char i : line){
        this->output += i;
    }
    return longestPeriod(line);
}


int longestPeriod(vector<char> line){
    int lineLength = line.size() - 1;
    int sep = line.size() / 2;
    vector<string> periods;
    string LHS, RHS, sample, fullLine, answer;
    for(int i = 0; i < sep; i++){
        LHS += line[i];
        RHS.insert(0, 1, line[lineLength - i]);
        if(LHS == RHS){
            periods.push_back(LHS);
        }
    }
    for(char i : line){
        fullLine += i;
    }
    if(!periods.size()){
        return 0;
    }
    else{
        for(string period : periods){
            if (!(line.size() % period.size())){
                int times = line.size() / period.size();
                for(int i = 0; i < times; i++){
                    sample += period;
                }
                if(sample == fullLine){
                    answer = period;
                    break;
                }
                sample = "";
            }
        }
    return answer.size();
    }
}