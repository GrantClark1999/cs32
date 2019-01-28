#include "Person.h"
#include <iostream>

using namespace std;

// default constructor
Person::Person() {
    name = "-";
    age = 0;
    v = new vector<int>();
    v->push_back(100);
}

// constructor overloading
Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
}

// copy constructor
Person::Person(Person& person) {
    name = person.getName();
    age = person.getAge();
    cout << "copy constructor" << endl;
}

Person::~Person() {
    cout << "this object address is = " << this << endl;
    delete v;
    cout << "Deleted the vector" << endl;
}

string Person::getName() const { return name; }

int Person::getAge() const { return age; }

vector<int>* Person::getVector() const { return v; }

void Person::setName(string name) { this->name = name; }

void Person::setAge(int age) { this->age = age; }




