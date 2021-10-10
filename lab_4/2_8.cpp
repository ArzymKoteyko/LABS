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
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	// sorting throwug even and odd rows
	for (i=0; i<n/2; i++) {
		int max_value_1 = matrix[ i*2 ][0];
		int max_value_2 = matrix[i*2+1][0];
		int max_index_1 = 0;
		int max_index_2 = 0;
		// searching for maximal values and their indexes in each odd and even rows
		for (j=0; j<n; j++) {
			if (matrix[ i*2 ][j] > max_value_1) {
				max_value_1 = matrix[ i*2 ][j];
				max_index_1 = j;
			}
			if (matrix[i*2+1][j] > max_value_2) {
				max_value_2 = matrix[i*2+1][j];
				max_index_2 = j;
			}
		}
		// swaping maximal value from odd row with maximal value from even row
		int buf;
		buf = matrix[ i*2 ][max_index_1];
		matrix[ i*2 ][max_index_1] = matrix[i*2+1][max_index_2];
		matrix[i*2+1][max_index_2] = buf;
	}

	// printing resulting matrix 
	cout << "Resulting matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			cout.width(4);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
