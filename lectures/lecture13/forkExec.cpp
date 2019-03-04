// forkExec.cpp
#include <unistd.h>
#include <iostream>

using namespace std;

// path to some executable
#define HELLO_EXECUTABLE "/Users/gclark/cs32/lectures/lecture13/hello"

int main() {

  cout << "Before fork, " << __FILE__ ", " << __LINE__ << " " <<
  __FUNCTION__ << endl;

  // parent receives child PID, child_result == 0
  pid_t result = fork();
  
  cout << "After fork, " << __FILE__ ", " << __LINE__ << " " <<
  __FUNCTION__ << endl;

  // Following if block executed only by child process
  if (result == 0) {
    int execvResult;
    char* const argv[] = { HELLO_EXECUTABLE };
    execvResult = execv(HELLO_EXECUTABLE, argv); // if success, executes then terminate

    // THIS LINE OF CODE NEVER REACHED IN CHILD
    // (unless execv returned an error)
    perror("execv seems to have failed");
    cout << "execvResult=" << execvResult << endl;
    exit(1);
  }

  //parent executes this
  //(busy wait to check if no child process exists)
  // https://linux.die.net/man/2/waitpid
  while (waitpid(result, NULL, 0)) {
    cout << "Waiting" << endl;
    if (errno == ECHILD) {
      cout << "pid: " << result << " has no child" << endl;
      break;
    }
  }

  cout << "After waiting, " << __FILE__ ", " << __LINE__ << " " <<
  __FUNCTION__ << endl;
  return 0;
} // Play around with ps –l between sleep to see PPID and PID