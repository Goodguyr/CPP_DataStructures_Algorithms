#include<iostream>
#include "Ratio.h"
#include "Matrix.h"

template <class T> Matrix<T>::Matrix(int rows_, int collumns_): rows(rows_), collumns(collumns_){
    currPos = 0;
    data = new T* [rows];
    for(int i = 0; i < rows; i++){
        data[i] = new T [collumns];
    }
}

template <class T> Matrix<T>::~Matrix(){
    for(int i = 0; i < rows; i++){
        delete[] data[i];
    }
    delete[] data;
}

template <class T> void Matrix<T>::addNumber(T num){
    int x = currPos / collumns; 
    data[x][currPos % collumns] = num;
    currPos++;
}

template<class T> Matrix<T>& subtractMatrices(Matrix<T>& a, Matrix<T>& b){
    if(a.getCol() != b.getCol() || a.getRow() != b.getRow()){
        std::cout << "out_of_range" << std::endl;
        return;
    }
    Matrix<T> result(a.getRow(), a.getCol());
    for(int i = 0; i < a.getRow(); i++){
        for(int j = 0; j < a.getCol(); j++){
            result.addNumber(a.getNum(i,j) - b.getNum(i,j));
        }
    }
    return result;
}

template<class T> Matrix<T>& addMatrices(Matrix<T>& a, Matrix<T>& b){
    if(a.getCol() != b.getCol() || a.getRow() != b.getRow()){
        std::cout << "out_of_range" << std::endl;
        return;
    }
    Matrix<T> result(a.getRow(), a.getCol());
    for(int i = 0; i < a.getRow(); i++){
        for(int j = 0; j < a.getCol(); j++){
            result.addNumber(a.getNum(i,j) + b.getNum(i,j));
        }
    }
    return result;
}

template<class T> Matrix<T>& multiplyMatrices(Matrix<T>& a, Matrix<T>& b){
    if(a.getCol() != b.getRow()){
        std::cout << "out_of_range" << std::endl;
        return;
    }
    Matrix<T> result(a.getRow(), b.getCol());
    for(int i = 0; i < a.getCol(); i++){
        for(int j = 0; j < b.getRow(); j++){
            for(int k = 0; k < a.getCol(); k++){
                result[i][j] += a.getNum(i,k) * b.getNum(k,j);
            }
        }
    }
    return result;
}
