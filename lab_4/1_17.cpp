#include <iostream>

using namespace std;

const int n = 3;
const int m = 6;
int matrix[n][m] = {{  0,  1, 12, -3,  4, -3},
					{  5,  2, -2, -2,  3, -4},
                    {  3, 10,  4, -2,  3,  0}};

int main(int argc, char *argv[]) {
	int i, j;

	// printing given matrix to consle
	cout << "Given matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(4);     // set left ident 
			cout << matrix[i][j];
		}
		cout << endl;
	}

	for (i=0; i<n; i++) {
		// min_indexes is an array with minimal values' position
		// at that if minimal values was found at third time 
		// min_idexes array will be: [0, 1, 0, 2, 3, 3, 0, 2]
		// and 3' indicates where minimal value is in matrix 
		int min_indexes[m];
		// initialize array with zeros
		for (j=0; j<m; j++) {
			min_indexes[j] = 0;
		}
		// initialize min_value with a first element of a row
		int min_value = matrix[i][0];
		// order in wich minimal value was found
		int min_order = 1;
		// ammount of minimal values 
		int min_amount = 1;
		// asuming that first value is in fact minimal value
		min_indexes[0] = min_order;
		
		// finding all minimal values in given row 
		// and save their positions to {min_indexes}
		// and their values to {min_value}
		for (j=0; j<m; j++) {
			if (matrix[i][j] == min_value) {
				min_indexes[j] = min_order;
				min_amount++;
			}
			else if(matrix[i][j] < min_value) {
				min_value = matrix[i][j];
				min_amount = 1;
				min_order++;
				min_indexes[j] = min_order;
			}
		}
		
		// moving non_minimal values to the left side
		int step = 0;
		for (j=m-1; j>=0+step; j--) {
			while (min_indexes[j-step] == min_order) {
				step++;
			}
			matrix[i][j] = matrix[i][j-step];
		}
		// restoring minimal_values at the begening of a row
		for (j=0; j<min_amount; j++) {
			matrix[i][j] = min_value;
		}
		

		// DEBUG
		/*
		// printing {min_idexes} to console

		for (j=0; j<m; j++) {
			cout << min_indexes[j] << " ";
		}
		cout << endl;

		// printing minimal value and mins ammount ro console

		cout << "Minimal value: ";
		cout.width(3);
		cout <<  min_value << "\t";
		cout << "Minimal values amount ";
		cout.width(3);
		cout << min_amount << endl;
		*/
		// DEBUG END
	}

	// printing resulting matrix to console
	cout << "Resulting matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(4);    // set left ident
			cout << matrix[i][j];   
		}
		cout << endl;
	}

	return 0;
}
