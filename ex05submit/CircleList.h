#include<string>

class CNode{
public:
    CNode(int num){
        value = num;
    };
    int value;
    CNode* next;
};

class CircleList{
    CNode* cursor;
    int size;
public:
    CircleList(){
        CNode* newNode = new CNode(0);
        cursor = newNode;
        size = 0;
    };
    ~CircleList();
    bool empty() const;
    const int& front() const;
    const int& back() const;
    void add(const int& num);
    void remove();
    void advance();
    int getSize();
    std::string to_str() const;
};