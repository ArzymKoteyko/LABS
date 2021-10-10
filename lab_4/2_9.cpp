#include <iostream>

using namespace std;

const int n = 6;
const int m = 7; 
int matrix[n][m] = {{ -2,  8,  5, -4, -9, -9,  3},
                    { -7, -3, -3,  9, -6, -5,  4},
                    { -8,  6, -4,  3,  0, -5,  0},
                    {  8,  6,  2,  9,  2, -4, -9},
                    {  1,  8, -8, -1, -9, -4,  1},
                    { -2, -2, -8,  3,  0,  2, -7}};

int main(int argc, char *argv[]) {
	int i, j, buf;
	// printing given matrix to console
	cout << "Given matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(4);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	// reversing rows in matrix
	for (i=0; i<n; i++) {
		for (j=0; j<m/2; j++) {
			buf = matrix[i][j];
			matrix[i][j] = matrix[i][m-j-1];
			matrix[i][m-j-1] = buf;
		}
	}

	// printing resulting matrix to console
	cout << "Resulting matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(4);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
