#include <string>
#include <sstream>
#include <iostream>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
    head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
    Node* newNode = new Node();
    Student* newStudent = new Student(s);
    newNode->s = newStudent;
    newNode->next = nullptr;

    // Inserting into an empty StudentRoll
    if(head == nullptr) {
        head = newNode;
    }
        // Inserting into a StudentRoll with only one entry
        // (where head != nullptr and tail == nullptr)
    else if(tail == nullptr) {
        head->next = newNode;
        tail = newNode;
    }
        // Inserting into a StudentRoll with >1 entry
        // (where both head and tail are not nullptr)
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

std::string StudentRoll::toString() const {
    std::ostringstream output;
    Node* iterator = head;
    output << "[";
    while(iterator) {
        output << iterator->s->toString();
        iterator = iterator->next;
        if(iterator != nullptr) output << ",";
    }
    output << "]";
    return output.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
    Node* iterator = orig.head;
    while(iterator) {
        insertAtTail(*(iterator->s));
        iterator = iterator->next;
    }
}

StudentRoll::~StudentRoll() {
    Node* iterator = head;
    while(head != nullptr) {
        iterator = iterator->next;
        delete head->s;
        delete head;
        head = iterator;
    }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
    // The next two lines are standard, and you should keep them.
    // They avoid problems with self-assignment where you might free up
    // memory before you copy from it.  (e.g. x = x)

    if (&right == this)
        return (*this);

    // TODO... Here is where there is code missing that you need to
    // fill in...
    Node* iterator = right.head;
    while(iterator != nullptr) {
        this->insertAtTail(*(iterator->s));
        iterator = iterator->next;
    }

    // KEEP THE CODE BELOW THIS LINE
    // Overloaded = should end with this line, despite what the textbook says.
    return (*this);

}






