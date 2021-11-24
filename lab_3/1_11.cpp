#include <iostream>

using namespace std;

//int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};			// res: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//int A[10] = {-1, 2, -3, 4, -5, 6, -7, 8, -9, 10};			// res: [2, 4, 6, 8, 10]
int A[10] = {-1, -2, -4, -5, 6, 7, 8, -10, 12, 13};			// res: [6, 7, 8, 12, 13]
int main () {
	
	
	// printing specified A
	cout << "Specified A's items: [ ";
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	cout << "]\n";
	
	// calculating new A size 
	int item_count = 0;
	for (int i = 0; i < 10; i++) {
		if (A[i] > 0) {
			item_count++;
		}
	}

	// creating new A
	int res[item_count];
	item_count = 0;
	for (int i = 0; i < 10; i++) {
		if (A[i] > 0) {
			res[item_count] = A[i];
			item_count++;
		}
	}


	// printing result
	cout << "Array of positive elements: [ ";
	for (int i = 0; i < item_count; i++) {
		cout << res[i] << " ";
	}
	cout << "]\n";
	return 0;
}
