#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // res -> [0, 2, 4, 6, 8] | [1, 3, 5, 7, 9]

int main () {

	// printing specified array
	cout << "Specified array's items: [ ";
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << "]\n";

	// calculating new odd and even arrays
	int odd[5];
	int even[5];

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			even[i/2] = array[i];
		}
		else {
			odd[i/2] = array[i];
		}
	}

	// printing even array
	cout << "Specified even array's items: [ ";
	for (int i = 0; i < 5; i++) {
		cout << even[i] << " ";
	}
	cout << "]\n";

	// printing odd array
	cout << "Specified odd array's items: [ ";
	for (int i = 0; i < 5; i++) {
		cout << odd[i] << " ";
	}
	cout << "]\n";

	return 0;
}
