#include<vector>

template <class T>
class Matrix{
private:
    int rows;
    int collumns;
    int currPos;
    T** data;
public:
    Matrix(int, int);
    ~Matrix();
    void addNumber(T);
    int getRow(){return rows;}
    int getCol(){return collumns;}
    T& getNum(int x, int y){return data[x][y];}
    friend Matrix<T>& multiplyMatrices(Matrix<T>&, Matrix<T>&);
    friend Matrix<T>& addMatrices(Matrix<T>&, Matrix<T>&);
    friend Matrix<T>& subtractMatrices(Matrix<T>&, Matrix<T>&);
};

template<class T> Matrix<T>& multiplyMatrices(Matrix<T>&, Matrix<T>&);
template<class T> Matrix<T>& addMatrices(Matrix<T>&, Matrix<T>&);
template<class T> Matrix<T>& subtractMatrices(Matrix<T>&, Matrix<T>&);