// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include "Person.h"

using namespace std;

template <class T>
void printVector(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
	cout << "v[" << i << "] = " << v[i] << endl;
	
	// range-based for loop example
	// int index = 0;
	// for (int i : v) {
	// 	cout << "v[" << index << "] = " << i << endl;
	// }

    }
}

void f() {
    Person* p = new Person();
    delete p; // Prevents memory leaks.
    return;
}

int main() {
    f();
    // Stack frame for f is removed
    return 0;
}
