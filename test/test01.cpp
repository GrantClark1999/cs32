#include <iostream>
using namespace std;

int main() {
    int increment = 0;
    int m = 20;
    int n = 10;
    
    for(int i = 1; i <= m; i++) {
	for(int j = 1; j <= n; j++) {
	    if(i != j) {
		increment++;
	    }
	}
    }

    cout << "Incremented " << increment << " times." << endl;
    
    return 0;
}
