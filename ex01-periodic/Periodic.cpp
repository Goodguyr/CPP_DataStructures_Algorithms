#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Periodic.h"
#include "solution.h"

using namespace ds_course;
using namespace std;

int longestPeriod(vector<char>);

Periodic::Periodic() {

}

int Periodic::isPeriodic(int number){
    string line;
    while(number){
        int temp = number % 10;
        char n = '0' + temp;
        line.insert(0,1,n);
        number = number / 10;
    }
    while(line[line.size() - 1] == '0'){
        line.erase(line.end() - 1);
    }
    this->output = "";
    for (char i : line){
        this->output += i;
    }
    return longestPeriod(line);
}


int Periodic::isPeriodic(string word, bool hex) {
    while(word[0] == '0'){
        word.erase(word.begin());
    }
    while(word[word.size() - 1] == '0'){
        word.erase(word.end() - 1);
    }
    if(hex){
        for(int i = 0; i < word.size(); i++){
            word[i] = tolower(word[i]);
        }
    }
    this->output = word;
    return longestPeriod(word);
}
