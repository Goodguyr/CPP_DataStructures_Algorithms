#include<iostream>
#include<string>
#include"CircleList.h"


CircleList::~CircleList(){

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
    CNode* next = cursor->next;
    CNode* i = cursor->next;
    while(i->next != cursor){
        i = i->next;
    }
    delete cursor;
    i->next = next;
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
    CNode* temp = cursor->next;
    while(temp != cursor){
        line += std::to_string(temp->value) + " ";
        temp = temp->next;
    }
    line += std::to_string(temp->value);
    return line;
};
