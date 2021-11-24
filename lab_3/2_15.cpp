#include <iostream>

using namespace std;

const int n = 8;
const int m = 6;
int A[n+m] = {-1,-2,-3,-4,-5,-6,-7,-8,0,0,0,0,0,0};
int B[n] = {1,2,3,4,5,6};
int k = 4;

int main () {
	for (int i=0; i<n; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	for (int i=0; i<m; i++) {
		cout << B[i] << " ";
	}
	cout << "\n";
	cout << "k: " << k << "\n";
    for (int i=n+m-1; i>k; i--) {
        A[i] = A[i-k-1];
    }
    int j = 0;
    for (int i=k; i<k+m; i++) {
        A[i] = B[j];
        j++;
    }
    for (int i=0; i<n+m; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    /*	
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
    */
	return 0;
}
