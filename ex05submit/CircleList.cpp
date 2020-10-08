#include<iostream>
#include<string>
#include"CircleList.h"


CircleList::~CircleList(){
    while(!empty()){
        remove();
    }
};

bool CircleList::empty() const {
    if(size){
        return false;
    }
    return true;
};

const int& CircleList::front() const {
    return cursor->next->value;
};

const int& CircleList::back() const {
    return cursor->value;
};

void CircleList::add(const int& num){
    if(empty()){
        cursor->value = num;
        cursor->next = cursor;
        size++;
        return;
    }
    CNode* newNode = new CNode(num);
    newNode->next = cursor->next;
    cursor->next = newNode;
    size++;
};

void CircleList::remove(){
    if(size == 1){
        size--;
        return;
    }
    CNode* next = cursor->next->next;
    delete cursor->next;
    cursor->next = next;
    size--;
};

void CircleList::advance(){
    cursor = cursor->next;
};

int CircleList::getSize(){
    return size;
};

std::string CircleList::to_str() const {
    std::string line = "";
    if(empty()){
        return line;
    }
    CNode* temp = cursor->next;
    while(temp != cursor){
        line += std::to_string(temp->value) + " ";
        temp = temp->next;
    }
    line += std::to_string(temp->value);
    return line;
};
