#include <iostream>

using namespace std;

int my_array[10] = {-1,-3,2,8,9,7,-2,-13,-4,-3};

int maxx = my_array[0];
int max_id = -1;

int main () {
    for (int i=0; i<10; i++) {
        cout << my_array[i] << " ";
    }
    cout << endl;
	for (int i=0; i<10/2; i++) {
		if (my_array[i*2] > maxx) {
			maxx = my_array[i*2];
			max_id = i*2;
		}
	}
	
	my_array[max_id] = max_id;
	for (int i=0; i<10; i++) {
		cout << my_array[i] << " ";
	}
	cout << "\n";
	return 0;
}
