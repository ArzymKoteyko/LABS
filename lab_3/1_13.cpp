#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // res -> [0, 2, 4, 6, 8] | [1, 3, 5, 7, 9]

int main () {

	// printing specified A
	cout << "Specified A's items: [ ";
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	cout << "]\n";

	// calculating new odd and even As
	int odd[5];
	int even[5];

	for (int i = 0; i < 10/2; i++) {
        even[i] = A[i*2];
		odd[i] = A[i*2+1];
	}

	// printing even A
	cout << "Specified even A's items: [ ";
	for (int i = 0; i < 5; i++) {
		cout << even[i] << " ";
	}
	cout << "]\n";

	// printing odd A
	cout << "Specified odd A's items: [ ";
	for (int i = 0; i < 5; i++) {
		cout << odd[i] << " ";
	}
	cout << "]\n";

	return 0;
}
