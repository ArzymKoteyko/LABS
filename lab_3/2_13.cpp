#include <iostream>

using namespace std;

int array[10] = {-1,-3,2,8,9,7,-2,-13,-4,-3};

int maxx = -1000000;
int max_id = -1;

int main () {
	for (int i=0; i<10; i++) {
		cout << array[i] << " ";
		if (i%2 == 0 && array[i] > maxx) {
			maxx = array[i];
			max_id = i;
		}
	}
	cout << "\n";
	
	array[max_id] = max_id;
	for (int i=0; i<10; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
	return 0;
}
