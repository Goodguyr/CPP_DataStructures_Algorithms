#include "Student.h"

using namespace ds_course;

Student::Student(){}

int Student::compareTo(Student ss){
    if(this->age > ss.age){
        return 1;
    }
    else if(this->age == ss.age){
        if(this->height > ss.height){
            return 1;
        }
        else if(this->height < ss.height){
            return -1;
        }
        return 0;
    }
    return -1;
}