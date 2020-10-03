#include<iostream>
#include<string>
#include<sstream>
#include"Ratio.h"
#include"Matrix.h"

using namespace std;

int main(){
    string matrixType, newLine;
    int rows, collumns;
    cin >> matrixType >> rows >> collumns;
    cin.ignore();
    if(matrixType == "MZ"){
        Matrix<int> firstMatrix(rows, collumns);
        cin >> firstMatrix;
        cin >> matrixType >> rows >> collumns;
        cin.ignore();
        if(matrixType == "MZ"){
            Matrix<int> secondMatrix(rows, collumns);
            cin >> secondMatrix;
            string action;
            cin >> action;
            if(action == "ADD"){
                Matrix<int> answer = firstMatrix + secondMatrix;
                cout << answer;
            }
            else if(action == "SUB"){
                Matrix<int> answer = firstMatrix - secondMatrix;
                cout << answer;
            }
            else if(action == "MUL"){
                Matrix<int> answer = firstMatrix * secondMatrix;
                cout << answer;
            }
            else{
                cout << "out_of_range" << endl;
                throw std::runtime_error("out_of_range");
            }
            return 0;
        }
        cout << "out_of_range" << endl;
        throw std::runtime_error("out_of_range");
    }
    else if(matrixType == "MR"){
        Matrix<double> firstMatrix(rows, collumns);
        cin >> firstMatrix;
        cin >> matrixType >> rows >> collumns;
        cin.ignore();
        if(matrixType == "MR"){
            Matrix<double> secondMatrix(rows, collumns);
            cin >> secondMatrix;
            string action;
            cin >> action;
            if(action == "ADD"){
                Matrix<double> answer = firstMatrix + secondMatrix;
                cout << answer;
            }
            else if(action == "SUB"){
                Matrix<double> answer = firstMatrix - secondMatrix;
                cout << answer;
            }
            else if(action == "MUL"){
                Matrix<double> answer = firstMatrix * secondMatrix;
                cout << answer;
            }
            else{
                cout << "out_of_range" << endl;
                throw std::runtime_error("out_of_range");
            }
            return 0;
        }
        cout << "out_of_range" << endl;
        throw std::runtime_error("out_of_range");
    }
    else if(matrixType == "MQ"){
        Matrix<Ratio> firstMatrix(rows, collumns);
        cin >> firstMatrix;
        cin >> matrixType >> rows >> collumns;
        cin.ignore();
        if(matrixType == "MQ"){
            Matrix<Ratio> secondMatrix(rows, collumns);
            cin >> secondMatrix;
            string action;
            cin >> action;
            if(action == "ADD"){
                Matrix<Ratio> answer = firstMatrix + secondMatrix;
                cout << answer;
            }
            else if(action == "SUB"){
                Matrix<Ratio> answer = firstMatrix - secondMatrix;
                cout << answer;
            }
            else if(action == "MUL"){
                Matrix<Ratio> answer = firstMatrix * secondMatrix;
                cout << answer;
            }
            else{
                cout << "out_of_range" << endl;
                throw std::runtime_error("out_of_range");
            }
            return 0;
        }
        cout << "out_of_range" << endl;
        throw std::runtime_error("out_of_range");
    }
    else{
        cout << "out_of_range" << endl;
        throw std::runtime_error("out_of_range");
    }
    return 0;
}