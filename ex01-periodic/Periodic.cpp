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

int Periodic::isPeriodic(string &word, string &mode){
    if(mode == "hex"){
        for(int i = 0; i < word.size(); i++){
            word[i] = tolower(word[i]);
        }
    }
    while(word[0] == '0'){
        word.erase(word.begin());
    }
    while(word[word.size() - 1] == '0'){
        word.erase(word.end() - 1);
    }
    this->output = word;
    return longestPeriod(word);
}
