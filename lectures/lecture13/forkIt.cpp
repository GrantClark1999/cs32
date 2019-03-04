#include <unistd.h> // sleep(), fork(), pid_t (in sys/types.h)
#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Before fork, " << __FILE__ << " " <<
   __LINE__ << " "  << __FUNCTION__ << endl;
  sleep(10);

  pid_t result = fork(); // child_result == 0, parent_result == PID of child

  cout << "After fork, " << __FILE__ << " " <<
   __LINE__ << " "  << __FUNCTION__ << endl;

  sleep(10);

  cout << "After sleep, " << __FILE__ << " " <<
   __LINE__ << " "  << __FUNCTION__ << endl;
  
  return 0;
}