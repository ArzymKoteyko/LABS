#include <iostream>

using namespace std;

const int row_to_change = 4;
const int n = 5;
int matrix[n][n] = {{  0,  2, -1,  3, 10},
	                {-12,  3, -3,  8,  0},
	                { -8, -3, 15,  0, 14},
	                {-12,  4, -3,  8,  5},
	                {  3,  4, -2,  2,  9}};

int main(int argc, char *argv[]) {
	int i, j;

	cout << "Given matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			cout.width(4);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	int max_value = matrix[0][0];
	int max_value_col = 0;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (matrix[i][j] > max_value) {
				max_value = matrix[i][j];
				max_value_col = j;
			}
		}	
	}	
	int buff;
	for (i=0; i<n; i++) {
		buff = matrix[i][row_to_change - 1];
		matrix[i][row_to_change - 1] = matrix[i][max_value_col];
		matrix[i][max_value_col] = buff;
	}

	cout << "Maximal value: " << max_value << endl;
	cout << "Maximal value column: " << max_value_col + 1 << endl;
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
