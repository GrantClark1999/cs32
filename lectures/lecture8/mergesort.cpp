#include <iostream>

using namespace std;

// algorithm from DS textbook
void merge(int a[], size_t leftArraySize, size_t rightArraySize) {

	// Note: we are assuming the left and right sub arrays are sorted

	int* tempArray;		    // tempArray to hold sorted elements
	size_t copied = 0; 	    // num elements copied to tempArray
	size_t leftCopied = 0;	// num elements copied from leftArray
	size_t rightCopied = 0;	// num elements copied from rightArray

	// create temp array
	tempArray = new int[leftArraySize + rightArraySize];

	// merge left and right arrays into temp in sorted order
	while ((leftCopied < leftArraySize) && (rightCopied < rightArraySize)) {
		if (a[leftCopied] < (a + leftArraySize)[rightCopied]) {
			tempArray[copied++] = a[leftCopied++];
		} else {
			tempArray[copied++] = (a + leftArraySize)[rightCopied++];
		}
	}

	// copy remaining elements from left/right sub arrays into tempArray

	// if elements in leftArray still exist, then ...
	while (leftCopied < leftArraySize) {
		tempArray[copied++] = a[leftCopied++];
	}


	// if elements in rightArray still exist, then ...
	while (rightCopied < rightArraySize) {
		tempArray[copied++] = (a + leftArraySize)[rightCopied++];
	}

	// Replace the sorted values into the original array
	for (int i = 0; i < leftArraySize + rightArraySize; i++) {
		a[i] = tempArray[i];
	}

	// free up memory
	delete [] tempArray;
}

void mergesort(int a[], size_t size) {
    size_t leftArraySize;
    size_t rightArraySize;

    if (size > 1) {
        leftArraySize = size / 2;
        rightArraySize = size - leftArraySize;

        // call mergesort on left array
        mergesort(a, leftArraySize);

        // call mergesort on right array
        mergesort((a + leftArraySize), rightArraySize);

        // left and right sorted arrays together
        merge(a, leftArraySize, rightArraySize);
    }
}

void printArray(const int a[], size_t size) {
	cout << "Printing Array" << endl;
	for (int i = 0; i < size; i++) {
		cout << "a[" << i << "] = " << a[i] << endl;
	}
}

int main() {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int b[] = {9,8,7,6,5,4,3,2,1,0};
	int c[] = {0,9,1,8,2,7,3,6,4,5};
	int d[] = {5,4,6,3,7,2,8,1,9,0};

	mergesort(a, 10);
	printArray(a, 10);
	cout << "----" << endl;
	mergesort(b, 10);
	printArray(b, 10);
	cout << "----" << endl;
	mergesort(c, 10);
	printArray(c, 10);
	cout << "----" << endl;
	mergesort(d, 10);
	printArray(d, 10);
	cout << "----" << endl;
}