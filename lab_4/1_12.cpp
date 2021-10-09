#include <iostream>

using namespace std;

// creating matrix with size n X m 
// and filling it with given elemnts
const int n = 6;
const int m = 7;
int matrix[n][m] = {{-1, 4, 5, 4, 0,-1, 1},
                    {-4,-1, 3, 4,10,10,-2},
                    {-9,-3, 0,-4,-1, 3,-2},
                    {-5,-2, 3, 2, 1, 4, 3},
                    {-2,-1,10, 4, 1, 0, 0},
                    {-4,-1, 0, 4, 0, 3,-2}};
// arrays that will contain idexes of rows and cols with maximum values in it
int max_rows[n];
int max_cols[m];

int main(int argc, char *argv[]) {
	// frequently used variables
	// predefined for future cycles
	int i, j;

	// printing given matrix to console
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(4);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	// maximum matrix value
	// as default first element of matrix
	int max_value = matrix[0][0];
	// oreder of last found maximal value
	int max_order = 1;
	// amount of found maximal values
	int max_amount = 1;
	// arrays with maximal value positions
	max_rows[0] = max_order;
	max_cols[0] = max_order;
	// searching for all maximal values
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			if (matrix[i][j] == max_value) {
				max_rows[i] = max_order;
				max_cols[j] = max_order;
				max_amount = 1;
			}
			else if (matrix[i][j] > max_value) {
				max_value = matrix[i][j];
				max_order++;
				max_rows[i] = max_order;
				max_cols[j] = max_order;
				max_amount++;
			}
		}
	}
	
	// DEBUG
	/*
	cout << max_value << " " << max_amount << endl;
	for (i=0; i<n; i++) {
		cout << max_rows[i] << " ";
	}
	cout << endl;
	for (i=0; i<m; i++) {
		cout << max_cols[i] << " ";
	}
	cout << endl;
	*/
	// DEBUG END
	
	// deleting all rows with maxes
	// and counting how many was deleted
	// rstep is deleted row counter
	// and also telling ident for moving rows in matrix	
	int rstep = 0; 
	for (i=0; i<n-max_amount; i++) {
		while (max_rows[i+rstep] == max_order) {
			rstep++;
		}
		for (j=0; j<m; j++) {
			matrix[i][j] = matrix[i+rstep][j];
		}
	}
	// deleting all cols with maxes
	// and counting how many was deleted
	// cstep is deleted col counter
	// and also telling ident for moving colums in matrix
	int cstep = 0;
	for (i=0; i<m-max_amount; i++) {
		while (max_cols[i+cstep] == max_order) {
			cstep++;
		}
		for (j=0; j<n; j++) {
			matrix[j][i] = matrix[j][i+cstep];
		}
	}

	// printing result matrix to console
	for (i=0; i<n-rstep; i++) {
		for (j=0; j<m-cstep; j++) {
			cout.width(4);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
