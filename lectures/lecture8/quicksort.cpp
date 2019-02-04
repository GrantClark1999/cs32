#include <iostream>

using namespace std;

void partition(int a[], size_t size, size_t& pivotIndex) {
	int pivot = a[0];		 // choose 1st value for pivot
	size_t left = 1;		 // index just right of pivot
	size_t right = size - 1; // last item in array
	int temp;

	while (left <= right) {
		// increment left if <= pivot
		while (left < size && a[left] <= pivot) {
			left++;
		}

		// decrement right if > pivot
		while (a[right] > pivot) {
			right--;
		}

		// swap left and right if left < right
		if (left < right) {
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
	}

	// swap pivot with a[right]
	pivotIndex = right;
	temp = a[0];
	a[0] = a[pivotIndex];
	a[pivotIndex] = temp;
}

void quicksort(int a[], size_t size) {
	size_t pivotIndex;		// index of pivot
	size_t leftSize;		// num elements left of pivot
	size_t rightSize;		// num elements right of pivot

	if (size > 1) {
		// partition a[] based on pivotIndex
		partition(a, size, pivotIndex);

		// Compute the sizes of left and right sub arrays
		leftSize = pivotIndex;
		rightSize = size - leftSize - 1;

		// recursive call sorting the left array
		quicksort(a, leftSize);

		// recursive call sorting the right array
		quicksort((a + pivotIndex + 1), rightSize);
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
	quicksort(a, 10);
	printArray(a, 10);
	cout << "----" << endl;
	quicksort(b, 10);
	printArray(b, 10);
	cout << "----" << endl;
	quicksort(c, 10);
	printArray(c, 10);
	cout << "----" << endl;
	quicksort(d, 10);
	printArray(d, 10);
	cout << "----" << endl;
	return 0;
}