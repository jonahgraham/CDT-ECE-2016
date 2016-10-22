//============================================================================
// Name        : HelloCPP.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int overloaded(int a) {
	return 0;
}
int overloaded(double a) {
	return 0;
}
int overloaded(string a) {
	return 0;
}
int overloaded(vector<int> a) {
	return 0;
}

int main() {
	string myString = "Hello ECE";
	vector<int> myVector (16, 0xece); //16 instances of 0xece in list

	overloaded(1);
	overloaded(1.0);
	overloaded(myString);
	overloaded(myVector);
	return 0;
}
