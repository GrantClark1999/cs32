#include <iostream>
#include <string>

#include "Person.h"
#include "Student.h"

using namespace std;

int main() {
    Student s("Student", 21, 1234567);

    cout << s.getName() << endl;
    cout << s.getAge() << endl;
    cout << s.getStudentId() << endl;

    Person p1("Grant", 19);
    Student s1("Chris Gaucho", 18, 1234567);

    Person p2 = s1; // Legal, a student IS a person.
    //Student s2 = p1; // Illegal, a person may NOT be a student.

    cout << p2.getName() << endl;
    cout << p2.getAge() << endl;
    //cout << p2.getStudentId() << endl: // ERROR! p2 doesn't have a studentId.

    Person* p3 = new Person("R1", 10);
    Student* s3 = new Student("JD", 21, 1234567);

    //Student* s4 = p3                          // ILLEGAL
    Person* p4 = s3;                            // Okay
    cout << p4->getName() << endl;
    cout << p4->getAge() << endl;
    //cout << p4->getStudentId() << endl;       // ILLEGAL

    // Destructors called in reverse (sub class -> base class)
    delete p3;
    cout << "---" << endl;
    delete s3;
    return 0;
}