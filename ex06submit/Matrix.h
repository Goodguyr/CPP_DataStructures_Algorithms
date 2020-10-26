#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<iostream>
#include<string>
#include<sstream>

template <class T>
class Matrix{
    int rows, collumns, currPos;
    T** data;
public:
    Matrix(int rows_, int collumns_): rows(rows_), collumns(collumns_){
        currPos = 0;
        data = new T* [rows];
        for(int i = 0; i < rows; i++){
            data[i] = new T [collumns];
        }
    }
    Matrix(){
        rows = 3;
        collumns = 3;
        currPos = 0;
        data = new T* [rows];
        for(int i = 0; i < rows; i++){
            data[i] = new T [collumns];
            for(int j = 0; j < collumns; j++){
                if(j == i){
                    data[i][j] = 1;
                    continue;
                }
                data[i][j] = 0;
            }
        }
    }
    // ~Matrix(){
    //     for(int i = 0; i < rows; i++){
    //         delete[] data[i];
    //     }
    //     delete data;
    // };
    void addNumber(T num){
        int x = currPos / collumns; 
        data[x][currPos % collumns] = num;
        currPos++;
    };
    int getRow(){return rows;}
    int getCol(){return collumns;}
    T& getNum(int x, int y){return data[x][y];}

    Matrix<T> operator-(Matrix<T>& b){
        if(this->getCol() != b.getCol() || this->getRow() != b.getRow()){
            std::cout << "out_of_range" << std::endl;
            throw std::runtime_error("out_of_range");
        }
        Matrix<T> result(b.getRow(), b.getCol());
        for(int i = 0; i < b.getRow(); i++){
            for(int j = 0; j < b.getCol(); j++){
                result.addNumber(this->getNum(i,j) - b.getNum(i,j));
            }
        }
        return result;
    }

    Matrix<T> operator+(Matrix<T>& b){
        if(this->getCol() != b.getCol() || this->getRow() != b.getRow()){
            std::cout << "out_of_range" << std::endl;
            throw std::runtime_error("out_of_range");
        }
        Matrix<T> result(b.getRow(), b.getCol());
        for(int i = 0; i < b.getRow(); i++){
            for(int j = 0; j < b.getCol(); j++){
                result.addNumber(this->getNum(i,j) + b.getNum(i,j));
            }
        }
        return result;
    };

    Matrix<T> operator*(Matrix<T>& b){
        if(this->getCol() != b.getRow()){
            std::cout << "out_of_range" << std::endl;
            throw std::runtime_error("out_of_range");
        }
        Matrix<T> result(this->getRow(), b.getCol());
        for(int i = 0; i < this->getRow(); i++){
            for(int j = 0; j < b.getCol(); j++){
                T a = 0;
                for(int k = 0; k < this->getCol(); k++){
                    a += this->getNum(i,k) * b.getNum(k,j);
                }
                result.addNumber(a);
            }
        }
        return result;
    };
};


#endif