#include <iostream>

using namespace std;

const int n = 7;
const int m = 5;
<<<<<<< HEAD
int matrix[n][m+1] = {{ -1,  3,  9,  1, -3,  0},
                      { -3, -5,  0,  3,  6,  0},
                      {  9,  6,  8,  9,  2,  0},
                      {  4,  4,  4,  3,  3,  0},
                      {  0,  1,  0, -1,  0,  0},
                      { -3, -2, -1,  0,  1,  0}, 
                      {  9,  8,  7,  6,  5,  0}};

int main(int argc, char *argv[]) {
    int i, j;
    
    for (i = 0; i<n; i++) {
        int min_value = matrix[i][0];
        cout.width(4);
        cout << matrix[i][0] << " ";
        for (j=1; j<m; j++) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
            }
            cout.width(4);
            cout << matrix[i][j] << " ";
        }
        matrix[i][m] = min_value;
        cout.width(4);
        cout << matrix[i][j] << " ";
        cout << endl;
    }

    for (i=0; i<n; i++) {
        int min_value = matrix[i][m];
        int min_id = i;
        for (j=i+1; j<n; j++) {
            
        }
    }

=======
int matrix[n][m] = {{ -9,  3,  7,  9, -3},
                    { -5,  8, -7,  8,  8},
                    { -9, -2, -8, -8,  7},
                    {  9,  6, -5,  2,  8},
                    {  9,  5,  8,  5, -3},
                    {  6,  8,  9,  7, -8},
                    { -4, -8, -8,  8,  0}};
int min_values[n];
int min_indexes[n];

int main(int argc, char *argv[]) {
	int i, j;
	cout << "Given matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}
	
	for (i=0; i<n; i++) {
		int minimal_value = matrix[i][0];
		int minimal_index = 0;
		for (j=0; j<m; j++) {
			if (matrix[i][j] < minimal_value) {
				minimal_value = matrix[i][j];
				minimal_index = j;
			}
		}
		min_values[i] = minimal_value;
		min_indexes[i] = minimal_index;
	}

	for (i=0; i<n; i++) {
		cout.width(3);
		cout << min_values[i] << " ";
	}
	cout << endl;
	for (i=0; i<n; i++) {
		cout.width(3);
		cout << min_indexes[i] << " ";
	}
	cout << endl;
	
	cout << "Resulting matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}
>>>>>>> 99af54ffa9112e2f6347de84c1e8131ef8664a6a

	return 0;
}
