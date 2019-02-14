// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

/*
    Person is a base class of Student
    Student is a derived class (of subclass) of Person
    The ':' operator here means the Student class inherits everything 
        from a Person class.
        - Public Inheritance: Public members of base class become public
          members of derived class. Protected members of base class become
          protected members of derived class.
        - Protected Inheritance: Public and protected members of base class
          become protected members of derived class.
        - Private Inheritance: Public and protected members of base class
          become private members of derived class.
*/
class Student : public Person {
public:
    Student(std::string name, int age, int studentId);
    ~Student();
    int getStudentId();
    void setStudentId(int id);

    //  Redefining inherited functions
    std::string getName();
private:
    int studentId;
};

#endif