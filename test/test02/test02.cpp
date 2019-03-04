#include <iostream>
using namespace std;

class A {
public:
    A() {}
};

class B : A {
public:
    B() {}
};

class C : B {
public:
    C() {}
};

int main() {
    int a[3] = {1,2,3};
    try {
        for(int i = 0; i < 3; i++) {
            cout << a[i] << endl;
            if(a[i]%2 == 0) {
                throw A();
            }
        }
    } catch (C c) {
        cout << "Caught!" << endl;
    }
    cout << "End of try-catch block" << endl;
}