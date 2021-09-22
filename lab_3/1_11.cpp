#include <iostream>

using namespace std;

//int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};			// res: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//int array[10] = {-1, 2, -3, 4, -5, 6, -7, 8, -9, 10};			// res: [2, 4, 6, 8, 10]
int array[10] = {-1, -2, -4, -5, 6, 7, 8, -10, 12, 13};			// res: [6, 7, 8, 12, 13]
int main () {
	
	
	// printing specified array
	cout << "Specified array's items: [ ";
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << "]\n";
	
	// calculating new array size 
	int item_count = 0;
	for (int i = 0; i < 10; i++) {
		if (array[i] > 0) {
			item_count++;
		}
	}

	// creating new array
	int res[item_count];
	item_count = 0;
	for (int i = 0; i < 10; i++) {
		if (array[i] > 0) {
			res[item_count] = array[i];
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
