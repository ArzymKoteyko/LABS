#include <iostream>
#include <cmath>

using namespace std;

const int n = 5;
const int m = 7;
int matrix[n][m] = {{  8,  7,  4, -6,  0,  2, -5},
                    { -9,  6,  8,  7, -8, -9,  7},
                    { -6, -4, -9, -6, -6,  8, -2},
                    { -7, -7,  6,  1, -8,  3, -4},
                    {  1, -2, -3, -2,  2, -4, -9}};

int main(int argc, char *argv[]) {
	int i, j;
	// printing given array to console
	cout << " Given matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(4);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	// finding minimal fabs value and its index
	// in second row of given matrix
	// and writing result to
	// {min_value} and {min_index}
	int min_value = fabs(matrix[1][0]);
	int min_index = 0;
	for (i=0; i<m; i++) {
		if (fabs(matrix[1][i]) < min_value) {
			min_value = fabs(matrix[1][i]);
			min_index = i;
		}
	}
	// DEBUG
	/*
	cout << min_value << " " << min_index << endl;
	*/
	// DEBUG END
	
	// deliting col after minimal value or second matrix row
	for (i=min_index+1; i<m-1; i++) {
		for (j=0; j<n; j++) {
			matrix[j][i] = matrix[j][i+1];
		}
	}	

	// printing result matrix to console
	cout << "Resilting matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m-1; j++) {
			cout.width(4);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

