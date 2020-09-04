#include <iostream>
#include<vector>
#include<string>
#include <algorithm>


using namespace std;


string operator* (string n, int k){
    string answer = "";
    for (int i = 0; i < k; i++){
        answer += n;
    }
    return answer;
}

bool allSame(string toCheck){
    char temp = toCheck[0];
    for (char i : toCheck){
        if (i != temp){
            return false;
        }
    }
    return true;
}

bool isPrime(int x){
    int half = x / 2;
    for (int i = 2; i < half; i++){
        if(!(x % i)){
            return false;
        }
    }
    return true;
}

int longestPeriod(string line){
    if(line.length() < 2){
        return 0;
    }
    int lineLength = line.size();
    int counter, adder = 1;
    if(lineLength & 1 || lineLength == 2){
        counter = 3;
        adder = 2;
        if(isPrime(lineLength)){
            if (allSame(line)){
                return 1;
            }
            return 0;
        }
    }
    else{
        counter = 2;
    }
    int periodLength = lineLength / counter;
    string period, smallPeriod;
    while (counter <= periodLength){
        period = line.substr(0,periodLength);
        smallPeriod = line.substr(0,counter);
        if(smallPeriod * (lineLength / counter) == line){
            if(allSame(smallPeriod)){
                return 1;
            }
            return smallPeriod.length();
        }
        else if(period * counter == line){
            return periodLength;
        }
        counter += adder;
    }
    return 0;
}