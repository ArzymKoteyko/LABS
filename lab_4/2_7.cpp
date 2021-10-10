#include <iostream>

using namespace std;

const int n = 6;
int matrix[n][n] = {{ -2,  8,  5, -4, -9, -9},
                    { -7, -3, -3,  9, -6, -5},
                    { -8,  6, -4,  3,  0, -5},
                    {  8,  6,  2,  9,  2, -4},
                    {  1,  8, -8, -1, -9, -4},
                    { -2, -2, -8,  3,  0,  2}};

int main(int argc, char *argv[]) {
	int i, j;
	
	// printing given matrix to console
	cout << "Given matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}
	
	// searching for minimal value and it's index
	int max_value = matrix[0][0];
	int max_index = 0;
	for (i=0; i<n; i++) {
		if (matrix[i][i] > max_value) {
			max_value = matrix[i][i];
			max_index = i;
		}
	}
	
	// replacing values
	for (i=0; i<max_index; i++) {
		for (j=i+1; j<n; j++) {
			matrix[i][j] = 0;
		}
	}

	// printing resulting matrix to console
	cout << "Resulting matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}

	return 0;
}
