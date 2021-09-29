#include <iostream>

using namespace std;

int A[8] = {-1,-2,-3,-4,-5,-6,-7,-8};
int B[6] = {1,2,3,4,5,6};
int k = 4;

int main () {
	for (int i=0; i<8; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	for (int i=0; i<6; i++) {
		cout << B[i] << " ";
	}
	cout << "\n";
	cout << "k: " << k << "\n";
	
	int *C = new int[6+8]; 
	
	for (int i=0; i<k; i++) {
		C[i] = A[i];
	}
	for (int i=k; i<k+6; i++) {
		C[i] = B[i-k];
	}
	for (int i=k+6; i<6+8; i++) {
		C[i] = A[i-6];
	}

	for (int i=0; i<8+6; i++) {
		cout << C[i] << " ";
	}
	cout << "\n";
	return 0;
}
