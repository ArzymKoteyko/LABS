#include <iostream>

using namespace std;

int array[10] = {-1,-3,2,8,9,7,-2,13,4,3};
int maxx = -100000;
int minn =  100000;
int max_id = -1;
int min_id = -1;

int main () {
	
	for (int i=0; i<10; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
	
	for (int i=0; i<10; i++) {
		if (array[i] < minn) {
			minn = array[i];
			min_id = i;
		}
		if (array[i] > maxx) {
			maxx = array[i];
			max_id = i;
		}
	}
	cout << min_id << " " << max_id << "\n";
	
	if (max_id < min_id) {
		int s = max_id;
		max_id = min_id;
		min_id = s;
	}

	int *new_array = new int[max_id-min_id-1];
	for (int i=0; i<max_id-min_id-1; i++) {
		new_array[i] = array[i+min_id+1];
		cout << new_array[i] << " ";
	}
	cout << "\n";

	return 0;
}
