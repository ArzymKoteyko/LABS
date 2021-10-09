#include <iostream>

using namespace std;

// initialazing matrix of size n X m
// with given elemts
const int n = 4;
const int m = 7; 
const int matrix[n][m] = {{ 10,  2,  4, -4, -5,  3, 23},
                          {  5, 13, 14,  1, 23, 44,  4},
                          { -4,  3, -4, -8, 34,  0, -4},
                          {  0,  0, -1,  1,  4, 99, -1}};
// initialazing array wich contains idexes of minimal values for each row
// with maximal hypotheticall size of n*m (case where eache row has indentical values) 
int minimal_idexes[n*m]; 

int main(int argc, char *argv[]) {
	int i, j;
	// printing matrix to console
	cout << "Given matrix" << endl;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(4);    // set right indent for values
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	
	int total_used_indexes = 0;
	for (i=0; i<n; i++) {
		int min_val = matrix[i][0];
		int cur_row_used_indexes = 0;
	
		// searching for minimal values in each matrix row	
		minimal_idexes[total_used_indexes] = 0;
		for (j=1; j<m; j++) {
			// in case of two or more indentical minimal values
			// save all their indexes 
			if (matrix[i][j] == min_val) {
				total_used_indexes++;
				cur_row_used_indexes++;
				minimal_idexes[total_used_indexes] = j;
			}
			// in case finding smaller value 
			// erase already found values and
			// start from last value of previous row
			else if (matrix[i][j] < min_val) {
				min_val = matrix[i][j];
				total_used_indexes -= cur_row_used_indexes;
				cur_row_used_indexes = 0;
				minimal_idexes[total_used_indexes] = j;
			}
		}
		total_used_indexes++;
	}

	// printing found indexes to console
	cout << "Result array with indexes of minimal items in each row" << endl;
	for (i=0; i<total_used_indexes; i++) {
		cout << minimal_idexes[i] << " ";
	}
	cout << endl;
	return 0;
}
