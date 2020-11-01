template <class T>
class Stack{
    int size, capacity;
    T* data;
public:
    Stack(){
        size = 0;
        capacity = 10;
        data = new T[capacity];
    };
    ~Stack(){
        delete[] data;
    };
    bool isEmpty(){
        if(size){
            return true;
        }
        return false;
    }
    void push(T item){
        mem_check();
        data[size] = item;
        size++;
    };
    T pop(){
        size--;
        return data[size];
    };
    void mem_check(){
        if(size == capacity){
            capacity *= 2;
            data = new T[capacity];
        }
    }
};