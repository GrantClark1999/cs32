// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(std::string name, int age);
    ~Person();
    std::string getName();
    int getAge();
    void setName(std::string name);
    void setAge(int age);
private:
    std::string name;
    int age;
};

#endif