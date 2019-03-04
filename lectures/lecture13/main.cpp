#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
    // Run program. Notice that when executing "$ top" from the cmd line, the main program will be running at near 100% CPU.
    // You can run multiple instances of this program, because the computer will have multiple cores to handle it.

    //while(true) {}

    // Check: true == true? (yes)
    // Don't use computer resources for 100 seconds.
    // Loop
    while(true) {
        sleep(100);
    }
    return 0;
}