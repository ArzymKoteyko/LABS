#include <iostream>

using namespace std;

const int n = 5;
const int m = 8;
int matrix[n][m] = {{ -1,  8,  6, -2,  8, -4, -7,  0},
                    { -3,  6, -8, -9, -8, -1, -1,  0},
                    { -9, -9, -6, -7, -4, -5,  0,  0},
                    { -5,  7,  5,  9,  5,  3, -2,  0},
                    {  4, -2, -2,  3, -9, -8, -2,  0}};
int my_vector[n] = { 100, 
                    -100, 
				    -100,
				     100,  
				    -100};


int main(int argc, char *argv[]) {
	int i, j;
	// printing given matrix to console
	cout << "Given matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m-1; j++) {
			cout.width(4);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	// finding minimal value and its index in fifth matrix row
	int min_value = matrix[4][0];
	int min_index = 0;
	for (i=1; i<m-1; i++) {
		if (matrix[4][i] < min_value) {
			min_value = matrix[4][i];
			min_index = i;
		}
	}
	
	// moving colums that came after minimal value to the left
	for (i=m-1;i>min_index;i--) {
		for (j=0; j<n; j++) {
			matrix[j][i] = matrix[j][i-1];
		}
	}
	
	// inserting given vector after minimal value
	for (i=0;i<n;i++) {
		matrix[i][min_index+1] = my_vector[i];
	}
	
	// printing resulting matrix
	cout << "Reulting matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(4);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
