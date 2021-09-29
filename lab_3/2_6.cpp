#include <iostream>
#include <cmath>

using namespace std;

int A[10] = {1,0,5,4,20,3,-2,13,-8,7};
int P = 100;

float average (int *array, int len) {
	float res = 0;
	for (int i=0; i<len; i++) {
		res += array[i];
	}
	res = res/len;
	return res;
}

int main () {
	for (int i=0; i<10; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	int ave = average(A, 10);
	int dif = fabs(A[0]-ave);
	int id = -1;
	for (int i=0; i<10; i++) {
		if (fabs(A[i]-ave) < dif) {
			dif = fabs (A[i]-ave);
			id = i;
		}
	}
	cout << ave << " " << dif << " " << id << "\n";
	int *new_array = new int[11];
	int c = 0;
	while (c <= id) {
		new_array[c] = A[c];
		c++;
	}
	new_array[c] = P;
	c++;
	for (int i=c; i<11;i++) {
		new_array[i] = A[i-1];
	}
	for (int i=0; i<11; i++) {
		cout << new_array[i] << " ";
	}
	cout << "\n";
	return 0;

}
