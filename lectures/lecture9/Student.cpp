//  Student.cpp
#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(string name, int age, int id) : Person(name, age) {
    studentId = id;
}

Student::~Student() {
    cout << "in Student Destructor" << endl;
}

int Student::getStudentId() { return studentId; }

void Student::setStudentId(int id) { studentId = id; }

//  Redefining inherited functions
string Student::getName() {
    return "STUDENT: " + Person::getName();
}