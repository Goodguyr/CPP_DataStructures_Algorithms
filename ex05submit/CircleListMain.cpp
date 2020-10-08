#include<iostream>
#include <sstream>
#include"CircleList.h"

using namespace std;

int main(){
	int size;
	cin >> size;
	cin.ignore();
	int curPos = 0;
	CircleList* myList = new CircleList;
	for(int i = 0; i < size; i++){
		int temp;
		cin >> temp;
		myList->add(temp);
		myList->advance();
		curPos++;
	}
	while(curPos != 0){
		curPos++;
		curPos %= myList->getSize();
		myList->advance();
	}
	cin.ignore();
	string line;
	getline(cin, line);
	while(line.size() > 1){
		cout << line << endl;
		istringstream ss(line); 
		int pos;
		string action;
		ss >> action;
		ss >> pos;
		if(action == "INS"){
			if(pos > myList->getSize()){
				cout << "OutOfBoundsException" << endl;
				return 0;
			}
			int num;
			ss >> num;
			for(int i = 0; i < pos; i++){
				myList->advance();
				curPos++;
			}
			myList->add(num);
		}
		else if(action == "DEL"){
			if(pos > myList->getSize() - 1){
				cout << "OutOfBoundsException" << endl;
				return 0;
			}
			for(int i = 0; i <= pos; i++){
				myList->advance();
				curPos++;
			}
			myList->remove();
			curPos--;
		}
		while(curPos != 0){
			curPos++;
			curPos %= myList->getSize();
			myList->advance();
		}
		cout << myList->to_str() << endl << endl;
		getline(cin, line);
	}
	cout << myList->to_str() << endl;
	return 0;
}
