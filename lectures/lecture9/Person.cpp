// Person.cpp
#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
}

Person::~Person() {
    cout << "in Person Destructor" << endl;
}

string Person::getName() { return name; }

int Person::getAge() { return age; }

void Person::setName(string name) { this->name = name; }

void Person::setAge(int age) { this->age = age; }