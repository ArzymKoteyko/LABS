#include <iostream>

using namespace std;

int array[10] = {-1,-3,2,8,9,7,-2,-13,-4,-3};
int P = 100;
int last_id = -1;

int main () {
	for (int i=0; i<10; i++) {
		cout << array[i] << " ";
		if (array[i] > 0) { 
			last_id=i;
		}
	}
	cout << "\n";

	int *new_array = new int[11];
	for (int i=0; i<last_id+1;i++) {
		new_array[i] = array[i];
	}
	new_array[last_id+1] = P;
	for (int i=last_id+2; i<11; i++) {
		new_array[i] = array[i-1];
	}

	for (int i=0; i<11; i++) {
		cout << new_array[i] << " ";
	}
	cout << "\n";
	return 0;
}
