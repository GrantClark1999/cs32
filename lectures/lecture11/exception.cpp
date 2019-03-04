#include <iostream>

using namespace std;

class NegativeValueException {};
class EvenValueException {};
class DivideByZeroException {};

class A {};
class B : public A {};
class C {};

void ex1() {
    int value;
    try {
        cout << "Enter a positive number: ";
        cin >> value;

        if(value < 0) {
            throw value;
        }

        cout << "The number entered is: " << value << endl;
    } catch (int e) {
        // Deal with the error
        cerr << "ERROR: The number entered is not positive." << endl;
    }

    cout << "Statement after try/catch block" << endl;
}

void ex2() {
    int value;
    try {
        cout << "Enter an odd, positive number: ";
        cin >> value;

        if(value < 0)
            throw NegativeValueException();
        if (value % 2 == 0)
            throw EvenValueException();

        cout << "The number entered is: " << value << endl;
    } catch (NegativeValueException) {
        // Deal with the error
        cout << "ERROR: The number entered is not positive." << endl;
    } catch (EvenValueException) {
        cout << "ERROR: The number entered is even." << endl;
    }

    cout << "Statement after try/catch block" << endl;
}

/*
    Problems with exception specifications
    - Run-time checking: Specifications checked at runtime rather than at
    compile time. Offer no guarantee that the exceptions have been handled.
    - Run-time overhead: Run-time checking requires the compiler to produce
    additional code that also hampers optimizations.
    - Unusable in generic code: Within generic code, it is not generally
    possible to know what types of exceptions may be thrown from operations
    on template arguments, so a precise exception specification cannot be
    written.
    - Exception specifications cause the program to terminate (or more
    precisely, call termination handlers) if the implemented failed to
    uphold the guarantee to ONLY throw the defined exceptions.
    - Thus, by calling a method with an exception specification (as a
    library user), you are making your code MORE prone to complete failure
    or termination. If the library function runs out-of-memory (std::bad_alloc)
    you will NOT get a chance to catch it, but you will be terminated instead.
*/
double divide(int numerator, int denominator) throw (DivideByZeroException) {
        if (denominator == 0) {
            throw DivideByZeroException();
        }
        return numerator / (double) denominator;
}

//  Exceptions are checked one-by-one until the first match occurs.
//  If we don't want to (or wouldn't know how) to handle the exception
//      where it occurred, we can "pass it up" to the caller and let
//      them handle the exception.

void ex3() {
    try {
        cout << divide(1,1) << endl;
        cout << divide(1,0) << endl; // ERROR
        cout << divide(2,2) << endl;
    } catch (DivideByZeroException) {
        cout << "Error: cannot divide by zero" << endl;
    }

    cout << "After try/catch block" << endl;
}

void ex4() {
    int value = 0;
    try {
        cout << "Enter a positive number: ";
        cin >> value;

        if (value < 0) {
            throw B();
        }
    } catch (C) {
        cout << "Type C caught" << endl;
    } catch (A) {
        cout << "Type A caught" << endl;
    } catch (B) {
        // WILL NEVER BE EXECUTED
        cout << "Type B caught" << endl;
    }

    cout << "After try catch block" << endl;
}

int main() {
    //ex1();
    //ex2();
    //ex3();
    ex4();
    return 0;
}