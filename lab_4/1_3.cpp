#include <iostream>

using namespace std;

const int n = 4; // size of an square matrix

// initializing square matrix of size n with given elements
int Matrix[n][n] = {{ 0, 1, 2, 3},   
                    { 4, 5, 6, 7},
                    { 8, 9,10,11}, 
                    {12,13,14,15}}; 
// expecting result: 60

int main(int argc, char *argv[]) {
	int i, j;

	// printing matrix to console
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			cout.width(4);
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}

	int diagonal_sum = 0; // two matrix diagonls elements' sum
						  // where elements on diagonals have indexes
						  // j = i           for main diagonal 
						  // j = n - i - 1   for side diagonal
	for (i=0; i<n; i++) {
		diagonal_sum += Matrix[i][i];
		diagonal_sum += Matrix[i][n-i-1];
	}

	//checking for double center element
	if (n%2!=0) {
		diagonal_sum -= Matrix[n/2+1][n/2+1];
	}

	// printing result to console
	cout << "Sum of diagonal elements: ";
	cout << diagonal_sum << endl;

	return 0;
}
