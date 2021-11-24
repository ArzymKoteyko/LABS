#include <iostream>

using namespace std;

int A[8] = {-1, -2, 4, 3, -6, 3, 0, 1}; 		// res -> index: 4 value: -6
//int A[8] = {0, -1, -2, -3, -4, -5, -6, 0}; 		// res -> index: 6 value: -6
//int A[8] = {0, 1, 0, 1, 0, 1, 2, 3}; 		// res -> NONE
int main () {
	
	// printing specified A
	cout << "Specified A's items: [ ";
	for (int i = 0; i < 8; i++) {
		cout << A[i] << " ";
	}
	cout << "]\n";
	
	// calculating index and value of last negative element
	int index = -1;
	int value;
	bool find = false;
	for (int i = 0; i < 8; i++) {
		if (A[i] < 0) {
			index = i;
			value = A[i];
			find = true;
		}
	}

	// printing result
	if (find) {
		cout << "last index: " << index << "\t\tvalue: " << value << "\n";
	}
	else {
		cout << "all elements are NON-negative\nlast index: NONE\tvalue: NONE\n";
	}
	return 0;
}
