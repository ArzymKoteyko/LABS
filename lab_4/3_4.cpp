#include <iostream>

using namespace std;

const int n = 5;
int A[n][n] = {{  4,  5, -3,  2,  4},
               {  0, -3, -4,  2,  3},  
               {  2,  3,  4,  5,  6},  
               { -2,  3,  4,  0,  0},  
               {  0,  0,  1,  0,  1}};

int main() {

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i=n-1; i>=n/2; i--) {
		for (int j=0; j<=i; j++) {
			A[i][j] = 1;
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	return 0;
}
