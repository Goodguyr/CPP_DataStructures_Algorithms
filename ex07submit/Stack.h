#include <cstdlib>

template <class T>
class Stack{
    int size, capacity;
    T* data;
public:
    Stack(){
        size = 0;
        capacity = 10;
        data = (T*)malloc(capacity * sizeof(T));
        data = new T[capacity];
    };
    ~Stack(){
        free(data);
    };
    bool isEmpty(){
        if(size){
            return false;
        }
        return true;
    }
    void push(T item){
        mem_check();
        data[size] = item;
        size++;
    };
    T pop(){
        if(!size){
            return 0;
        }
        size--;
        return data[size];
    };
    T peek(){
        return data[size - 1];
    }
    void mem_check(){
        if(size == capacity){
            capacity *= 2;
            data = (T*)realloc(data, capacity * sizeof(T));
        }
    }
};