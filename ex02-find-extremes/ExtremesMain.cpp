#include<iostream>
#include "Student.h"

using namespace std;
using namespace ds_course;

Student getMin(Student* ss, int count){
    Student min = *ss;
    ss++;
    for(int i = 0; i < count - 1; i++){
        if(min.compareTo(*ss) == 1){
            min = *ss;
        }
        ss++;
    }
    return min;
}

Student getMax(Student* ss, int count){
    Student max = *ss;
    ss++;
    for(int i = 0; i < count - 1; i++){
        if(max.compareTo(*ss) == -1){
            max = *ss;
        }
        ss++;
    }
    return max;
}

int main(){
    int count;
    cin >> count;
    Student classOfStudents[count];
    for(int i = 0; i < count; i++){
        long long int age;
        long double height;
        cin >> age >> height;
        Student newStudent;
        newStudent.age = age;
        newStudent.height = height;
        classOfStudents[i] = newStudent;
    }
    Student minStudent = getMin(classOfStudents, count);
    Student maxStudent = getMax(classOfStudents, count);
    cout.setf(ios::fixed, 1);
    cout << minStudent.age << " " << minStudent.height << endl;
    cout << maxStudent.age << " " << maxStudent.height << endl;
    return 0;
}