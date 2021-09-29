#include <iostream>

using namespace std;

int array[10] = {-1,-3,2,8,9,7,-2,13,4,3};
int minn = 1000000;
int min_id = -1;

int main () {
	for (int i=0; i<10; i++) {
		cout << array[i] << " ";
		if (array[i]>0 && array[i]<minn) {
			minn = array[i];
			min_id = i;
		}
	}
	cout << "\n";
	cout << minn << " " << min_id << "\n";
	int *new_array = new int[9];
	int c = 0;
	while (c < min_id) {
		new_array[c] = array[c];
		c++;
	}
	c++;
	for(int i=c; i<10;i++) {
		new_array[i-1]=array[i];
	}
	for (int i=0; i<9;i++) {
		cout << new_array[i] << " ";
	}
	cout << "\n";
	return 0;
}
