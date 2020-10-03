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
    ~Matrix(){
        for(int i = 0; i < rows; i++){
            delete[] data[i];
        }
        delete[] data;
    };
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
                T temp = 0;
                for(int k = 0; k < this->getCol(); k++){
                    T answ = this->getNum(i,k) * b.getNum(k,j);
                    temp += answ;
                }
                result.addNumber(temp);
            }
        }
        return result;
    };

    friend std::ostream& operator<<(std::ostream &out, Matrix<T>& matrix);
    friend std::istream& operator>>(std::istream &in, Matrix<T>& matrix);
};

std::ostream& operator<<(std::ostream &out, Matrix<int>& matrix){
    out << "MZ " << matrix.getRow() << " " << matrix.getCol() << "\n";
    for(int i = 0; i < matrix.getRow(); i++){
        for(int j = 0; j < matrix.getCol(); j++){      
            out << matrix.getNum(i,j);
            if(j + 1 == matrix.getCol()){
                out << "\n";
                continue;
            }
            out << " ";
        }
    }
    return out;
};
std::ostream& operator<<(std::ostream &out, Matrix<double>& matrix){
    out << "MR " << matrix.getRow() << " " << matrix.getCol() << "\n";
    for(int i = 0; i < matrix.getRow(); i++){
        for(int j = 0; j < matrix.getCol(); j++){      
            out << matrix.getNum(i,j);
            if(j + 1 == matrix.getCol()){
                out << "\n";
                continue;
            }
            out << " ";
        }
    }
    return out;
};
std::ostream& operator<<(std::ostream &out, Matrix<Ratio>& matrix){
    out << "MQ " << matrix.getRow() << " " << matrix.getCol() << "\n";
    for(int i = 0; i < matrix.getRow(); i++){
        for(int j = 0; j < matrix.getCol(); j++){      
            out << matrix.getNum(i,j);
            if(j + 1 == matrix.getCol()){
                out << "\n";
                continue;
            }
            out << " ";
        }
    }
    return out;
};

std::istream& operator>>(std::istream &in, Matrix<int>& matrix){
    std::string line;
    for(int i = 0; i < matrix.getRow(); i++){
        getline(in, line);
        std::istringstream ss(line);
        int buffer;
        while(ss >> buffer){
            matrix.addNumber(buffer);
        }
    }
    return in;
};

std::istream& operator>>(std::istream &in, Matrix<double>& matrix){
    std::string line;
    for(int i = 0; i < matrix.getRow(); i++){
        getline(in, line);
        std::istringstream ss(line);
        double buffer;
        while(ss >> buffer){
            matrix.addNumber(buffer);
        }
    }
    return in;
};

std::istream& operator>>(std::istream &in, Matrix<Ratio>& matrix){
    std::string line;
    for(int i = 0; i < matrix.getRow(); i++){
        getline(in, line);
        int numCount(0);
        std::string currentRatio;
        std::string space = " ";
        while((numCount = line.find(space)) != std::string::npos){
            currentRatio = line.substr(0, numCount);
            int slashPos = currentRatio.find("/");
            int numerator = stoi(currentRatio.substr(0,slashPos));
            int denominator = stoi(currentRatio.substr(slashPos + 1, currentRatio.length()));
            matrix.addNumber(Ratio(numerator, denominator));
            line.erase(0, numCount + 1);
        }
        int slashPos = line.find("/");
        int numerator = stoi(line.substr(0,slashPos));
        int denominator = stoi(line.substr(slashPos + 1, line.length()));
        matrix.addNumber(Ratio(numerator, denominator));
    }
    return in;
};