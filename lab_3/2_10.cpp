#include <iostream>

using namespace std;

int my_array[10] = {-1,-3,2,8,9,7,-2,13,4,3};
int minn;
int min_id = -1;

int main () {
    int i;
	for (i=0; i<10; i++) {
        if (my_array[i] > 0) {
            minn = my_array[i];
            min_id = i;
            break;
        }
	cout << my_array[i] << " ";
    }
    for (;i<10;i++) {
        if (my_array[i] < minn && my_array[i] > 0) {
            minn = my_array[i];
            min_id = i;
        }
	cout << my_array[i] << " ";
	}
	cout << "\n";
	cout << minn << " " << min_id << "\n";
    
    for (i=min_id; i<10-1;i++) {
        my_array[i] = my_array[i+1];
    }
	for (int i=0; i<10-1;i++) {
		cout << my_array[i] << " ";
	}
	cout << "\n";
	return 0;
}
