#include <string>
#include <sstream>
#include <iostream>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
    head = tail = nullptr;
}

void StudentRoll::insertAtTail(const Student &s) {
    Node* newNode = new Node();
    Student* newStudent = new Student(s);
    newNode->s = newStudent;
    newNode->next = nullptr;

    // Inserting into an empty StudentRoll
    if(head == nullptr) {
	head = newNode;
	tail = newNode;
    }
    // Inserting into a StudentRoll with only one entry
    else if(head == tail) {
	tail = newNode;
	head->next = tail;
    }
    // Inserting into a StudentRoll with >1 entry
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
    head = nullptr;
    tail = nullptr;
    Node* iterator = orig.head;
    while(iterator) {
      insertAtTail(*(iterator->s));
      iterator = iterator->next;
    }
}

StudentRoll::~StudentRoll() {
    Node* iterator = head;
    while(iterator) {
      Node* next = iterator->next;
      delete iterator->s;
      delete iterator;
      iterator = next;
    }
    head = tail = nullptr;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
      return (*this);

  // Makes sure the node being assigned is empty before assignment.
  Node* iterator = head;
  if(head != nullptr) {
    while(iterator) {
      Node* next = iterator->next;
      delete iterator->s;
      delete iterator;
      iterator = next;
    }
    head = tail = nullptr;
  }

  // Assignment
  iterator = right.head;
  while(iterator) {
    Student* copyStudent(iterator->s);
    this->insertAtTail(*copyStudent);
    iterator = iterator->next;
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}
