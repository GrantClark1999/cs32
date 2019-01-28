#include <iostream>

using namespace std;

void binarySearch(const int a[], size_t first, size_t size, int target,
	    bool &found, size_t &location) {
    
     size_t middle;
     // base case
     if(size == 0) found = false;
     else {
	 middle = first + size/2;

	 // found the target
	 if(target == a[middle]) {
	     location = middle;
	     found = true;
	 }
	 else if(target < a[middle]) {
	     // recurse lower-half
	     binarySearch(a, first, middle, target, found, location);
	 }
	 else {
	     // recurse upper-half
	     binarySearch(a, middle + 1, (size-1)/2, target, found, location);
	 }
     }	 
}

// O(n^2) time-complexity
void bubbleSort(int a[], size_t size) {
    int temp;
    bool swapped;

    for(int i = size-1; i > 0; i--) {
	swapped = false;
	for(int j = 0; j < i; j++) {
	    if(a[j] > a[j+1]) {
		// swap
		temp = a[j];
		a[j] = a[j+1];
		a[j+1] = temp;
		swapped = true;
	    }
	}
	if(!swapped) {
	    // in order
	    cout << "i = " << i << endl;
	    cout << "already in order... returning" << endl;
	    return;
	}
    }
}

// O(n^2) time-complexity
// Similar to bubble sort. Searches array for largest value, then
// places it at the end of the array and moves the marker for the
// unsorted part of the array once to the left, splitting the array
// into an unsorted left-half, and a sorted right-half.
void selectionSort(int a[], size_t size) {
    int temp;
    int largestIndex;
    int largest;
    for(int i = size-1; i > 0; i--) {
	largestIndex = 0;
	largest = a[0];
	for(int j = 1; j <= i; j++) {
	    if(a[j] > largest) {
		largest = a[j];
		largestIndex = j;
	    }
	}
	temp = a[i];
	a[i] = a[largestIndex];
	a[largestIndex] = temp;
    }
}

// O(n^2) time-complexity
void insertionSort(int a[], size_t size) {
    int item;
    int shiftIndex;
    for(int i = 1; i < size; i++) {
	item = a[i];
	shiftIndex = i-1;
	while(shiftIndex >= 0 && a[shiftIndex] > item) {
	    a[shiftIndex+1] = a[shiftIndex];
	    shiftIndex -= 1;
	}
	a[shiftIndex+1] = item;
    }
}

void printArray(const int a[], size_t size) {
    for(int i = 0; i < size; i++) {
	cout << "[" << i << "]" << a[i] << endl;
    }
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int b[] = {1,10,2,9,3,8,4,7,5,6};
    int c[] = {2,9,4,7,6,5,8,3,10,1};
    int d[] = {10,9,8,7,6,5,4,3,2,1};
    int e[] = {1};
    bool exists = false;
    size_t location;

    cout << "Binary Search" << endl;
    cout << "----------------" << endl;

    binarySearch(a, 0, 10, 3, exists, location);
    cout << "3 exists: " << exists << endl;
    cout << "index of 3: " << location << endl;

    cout << "----" << endl;

    binarySearch(a, 0, 10, 11, exists, location);
    cout << "11 exists: " << exists << endl;
    cout << "index of 11: " << location << endl;

    cout << "----" << endl;
    
    binarySearch(a, 0, 10, 9, exists, location);
    cout << "9 exists: " << exists << endl;
    cout << "index of 9: " << location << endl;

    cout << "Bubble Sort" << endl;
    cout << "----------------" << endl;
    
    bubbleSort(a, 10);
    printArray(a,10);
    cout << "---" << endl;
    bubbleSort(b, 10);
    printArray(b,10);
    cout << "---" << endl;
    bubbleSort(c,10);
    printArray(c,10);
    cout << "---" << endl;
    bubbleSort(d,10);
    printArray(d,10);
    cout << "---" << endl;
    bubbleSort(e,1);
    printArray(e,1);

    return 0;
}
