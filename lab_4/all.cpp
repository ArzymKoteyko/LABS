//1_3
#include <iostream>

using namespace std;

const int n = 4; // size of an square matrix

// initializing square matrix of size n with given elements
int Matrix[n][n] = {{ 0, 1, 2, 3},   
                    { 4, 5, 6, 7},
                    { 8, 9,10,11}, 
                    {12,13,14,15}}; 
// expecting result: 60

int main(int argc, char *argv[]) {
	int i, j;

	// printing matrix to console
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			cout.width(4);
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}

	int diagonal_sum = 0; // two matrix diagonls elements' sum
						  // where elements on diagonals have indexes
						  // j = i           for main diagonal 
						  // j = n - i - 1   for side diagonal
	for (i=0; i<n; i++) {
		diagonal_sum += Matrix[i][i];
		diagonal_sum += Matrix[i][n-i-1];
	}

	//checking for double center element
	if (n%2!=0) {
		diagonal_sum -= Matrix[n/2+1][n/2+1];
	}

	// printing result to console
	cout << "Sum of diagonal elements: ";
	cout << diagonal_sum << endl;

	return 0;
}

//1_6
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


//1_12
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

//1_13
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

//1_17
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


//1_29
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


//1_31
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


//2_7
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


//2_8
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


//2_9
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


//3_1
#include <iostream>

using namespace std;

const int n = 7;
const int m = 5;
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

	return 0;
}


//3_2
#include <iostream>

using namespace std;

const int n = 5;

/*
int A[n][n] = {{  4,  5, -3,  2,  4},
               {  0, -3, -4,  2,  3},  
               {  2,  3,  4,  5,  6},  
               { -2,  3,  4,  0,  0},  
               {  0,  0,  1,  0,  1}};
*/
int A[n][n] = {{  1,  1,  1,  1,  1},
               {  1,  1,  1,  1,  1},  
               {  1,  1,  1,  1,  1},  
               {  1,  1,  1,  1,  1},  
               {  1,  1,  1,  1,  1}};

template <typename type, int len> 
void print (type array[len][len]) {
	for (int i=0; i<len; i++) {
		for (int j=0; j<len; j++) {
			cout.width(3);
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	int i;
	print<int, n> (A);
	cout << endl;
	for (i=1; i<n-1; i++) {
		A[i][0] = 0;
		A[0][i] = 0;
		A[i][n-1] = 0;
		A[n-1][i] = 0;
	}
	A[0][0] = 0;
	A[0][n-1] = 0;
	A[n-1][0] = 0;
	A[n-1][n-1] = 0;
	print<int, n> (A);
	return 0;
}


//3_3
#include <iostream>

using namespace std;

const int n = 5;

int A[n][n] = {{  4,  5, -3,  2,  4},
               {  0, -3, -4,  2,  3},  
               {  2,  3,  4,  5,  6},  
               { -2,  3,  4,  0,  0},  
               {  0,  0,  1,  0,  1}};
int Sum[2*n-1];

int main() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			Sum[n-1-i] += A[j][j-i];
			Sum[n-1+i] += A[j-i][j];
		}
	}
	Sum[n-1] /= 2;
	for (int i=0; i<(2*n-1); i++) {
		cout << Sum[i] << " ";
	}
	cout << endl;
	return 0;
}


//3_4
#include <iostream>

using namespace std;

const int n = 5;
int A[n][n] = {{  4,  5, -3,  2,  4},
               {  0, -3, -4,  2,  3},  
               {  2,  3,  4,  5,  6},  
               { -2,  3,  4,  0,  0},  
               {  0,  0,  1,  0,  1}};

int main() {

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i=n-1; i>=n/2; i--) {
		for (int j=0; j<=i; j++) {
			A[i][j] = 1;
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	return 0;
}


//3_8
#include <iostream>

using namespace std;

const int n = 7;
const int m = 5;

int A[n][m] = {{  3,  5, -3,  0, -3},  
               {  3,  4,  5,  2,  1},  
               { -2,  3, -1,  0,  0},  
               { -3, -2,  0,  0, -1},  
               {  3,  5,  2,  1,  3},  
               { -3,  2, -3,  0,  1},  
               { -3,  1,  3,  5,  2}};

int main() {
	int i,j,k;
	int max, pos_amount;
	int max_id;
	int buff;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	for (i=0; i<n; i++) {
		max = 0;
		max_id = i;
		for (j=i; j<n; j++) {
			pos_amount = 0;
			for (k=0; k<m; k++) {
				if (A[j][k] > 0) {
					pos_amount++;	
				}
			}
			if (pos_amount > max) {
				max = pos_amount;
				max_id = j;
			}
		}
		for (j=0; j<m; j++) {
			buff = A[i][j];
			A[i][j] = A[max_id][j];
			A[max_id][j] = buff;
		}
	}
	
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}


//3_10
#include <iostream>

using namespace std;

const int n = 7;
const int m = 9;

int A[n][m] = {{  3,  5, -3,  0, -3,  5,  6,  8,  0},  
               {  3,  4,  5,  2,  1, -3,  5,  9,  9},  
               { -2,  3, -1,  0,  0, -2, -3,  0, -8},  
               { -3, -2,  0,  0, -1,  9,  0,  0,  8},  
               {  3,  5,  2,  1,  3, -5,  0, -4,  2},  
               { -3,  2, -3,  0,  1,  1,  3,  5,  2},  
               { -3,  1,  3,  5,  2, -2, -3,  2,  0}};
int main() {
	int i,j,k;
	int min_odd, max_even;
	int min_id, max_id;
	int buff;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (i=0; i<n; i++) {
		for (j=0; j<m/2; j++) {
			
			min_odd  = A[i][j*2+1];
			max_even = A[i][j*2];
			min_id = j*2+1;
			max_id = j*2;
			
			for (k=j; k<m/2; k++) {
				if (A[i][k*2] > max_even) {
					max_even = A[i][k*2];
					max_id = k*2;
				}
				if (A[i][k*2+1] < min_odd) {
					min_odd = A[i][k*2+1];
					min_id = k*2+1;
				}
			}
			if (m%2==1 && A[i][m-1] > max_even) {
				max_even = A[i][m-1];
				max_id = m-1;
			}

			buff = A[i][min_id];
			A[i][min_id] = A[i][j*2+1];
			A[i][j*2+1] = buff;

			buff = A[i][max_id];
			A[i][max_id] = A[i][j*2];
			A[i][j*2] = buff;
		}
	}
	
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	return 0;
}

//3_11
#include <iostream>

using namespace std;

const int n = 7;
const int m = 9;
int A[n][m] = {{  3,  5, -3,  0, -3,  5,  6,  8,  0},  
               {  3,  4,  5,  2,  1, -3,  5,  9,  9},  
               { -2,  3, -1,  0,  0, -2, -3,  0, -8},  
               { -3, -2,  0,  0, -1,  9,  0,  0,  8},  
               {  3,  5,  2,  1,  3, -5,  1, -4,  2},  
               { -3,  2, -3,  0,  1,  1,  3,  5,  2},  
               { -3,  1,  3,  5,  2, -2, -3,  2,  1}};
int main() {
	int i,j,k;
	int del=0;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (i=0; i<n-del; i++) {
		for (j=0; j<m; j++) {
			if (A[i][j] == 0) {
				for (k=0; k<m; k++) {
					A[i][k] = A[n-del-1][k];
				}
				i--;
				del++;
				break;
			}
		}
	}

	for (i=0; i<n-del; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
