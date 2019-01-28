#include <string>
#include <iostream>
#include <unordered_map>
#include <utility> // For std::pair
using namespace std;

int main() {
  
  unordered_map<int, string> students; // hash table


  // Use bracket notation for creation
  students[0] = "Richert";
  students[1] = "John Doe";
  students[2] = "Jane Doe";
  students[251] = "someone!";

  cout << "students[1] = " << students[1] << endl;
  cout << "students[251] = " << students[251] << endl;
  cout << "students[101] = " << students[101] << endl;

  // Check if a student id exists using .find method
  if (students.find(1) != students.end()) {
    cout << "Found student id = 1, Name = " << students[1] << endl;
  }
  else {
    cout << "Can't find id = 1" << endl;
  }

  cout << "----" << endl;

  for(unordered_map<int, string>::iterator i = students.begin();
      i != students.end(); i++) {
    cout << i->first << " : " << i->second << endl;
  }

  students.insert(pair<int, string>(3, "Sleepy"));

  // Erasing by iterator
  unordered_map<int, string>::iterator p = students.find(2);
  students.erase(p); // erases "Jane Doe"

  // Erasing by key
  students.erase(0); // erases "Richert"

  // Does not replace existing item
  students.insert(pair<int, string>(1, "Some other John Doe"));
  students[1] = "Some other John Doe"; // replaces existing item

  return 0;
}
