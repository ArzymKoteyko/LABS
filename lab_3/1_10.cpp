#include <iostream>
#include <cmath>

using namespace std;

int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int P = 3;
int Q = 8;

int main () {
	
	// printing specified cords
	cout << "Specified array's items: [ ";
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << "]\n";
	cout << "P: " << P << "\tQ: " << Q << "\n";
	
	// counting and printing elemnts in range (P;Q)
	int counter = 0;
	for (int i = 0; i < 10; i++) {
		if (array[i] > P && array[i] < Q) {
			cout << array[i] << " ";
			counter++;
		}
	}

	// printing result
	cout << "\nAmount of items in given range: " << counter << "\n";
	return 0;
}
