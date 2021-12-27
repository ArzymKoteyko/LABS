// LEVEL 1
// TASK 1

#include <iostream>

using namespace std;

int fact(int x) {
	int res = 1;
	if (x == 0) {
		return 1;
	}
	for (int i=1; i<=x; i++) {
		res *= i;
	}
	return res;
}

int permutation(int k, int n) {
	return fact(n) / (fact(k) * fact(n - k));
}


int main () {
	cout << permutation(5, 8) << endl;
	cout << permutation(5, 10) << endl;
	cout << permutation(5, 11) << endl;
	return 0;
}

//-----------------------------------------------//
// LEVEL 1
// TASK 2

#include <iostream>
#include <cmath>

using namespace std;

template <typename T_A, typename T_B, typename T_C>
float squre (T_A a, T_B b, T_C c) {
	float p =  (float(a) + float(b) + float(c)) / 2;
	float epsilon = p*(p-a)*(p-b)*(p-c);
	float res = sqrt(epsilon);
	return res;
}

int main () {
	cout << squre(2,3.5,4) << endl;
	return 0;
}

//-----------------------------------------------//
// LEVEL 2
// TASK 6

#include <iostream>

using namespace std;

const int a_len_init = 7;
const int b_len_init = 8;

int a_len = a_len_init;
int b_len = b_len_init;

int A[a_len_init + b_len_init] = {1,-2,-3,4,-5,-6,-7,0,0,0,0,0,0,0,0};
int B[b_len_init] = {10,20,30,40,-50,60,-70,-80};

void del (int *array, int *len, int idx) {
	for (int i=idx; i<*len-1; i++) {
		array[i] = array[i+1];
	}
	*len -= 1;
}

void print_array (int *array, int *len) {
	for (int i=0; i<*len; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int max (int *array, int *len) {
	int idx = 0;
	int max = array[0];
	for (int i=0; i<*len; i++) {
		if (array[i] > max) {
			max = array[i];
			idx = i;
		}
	}
	return idx;
}

void concat(int *a_array, int *a_len, int *b_array, int *b_len) {
	for (int i=0; i<*b_len; i++) {
		a_array[i+(*a_len)] = b_array[i];
	}
	*a_len += *b_len;
}

int main() {
	print_array(A, &a_len);
	print_array(B, &b_len);
	del(A, &a_len, max(A, &a_len));
	del(B, &b_len, max(B, &b_len));
	concat(A, &a_len, B, &b_len);	

	print_array(A, &a_len);
	print_array(B, &b_len);

	return 0;
}

//-----------------------------------------------//
// LEVEL 2
// TASK 10

#include <iostream>
#include <vector>

using namespace std;

const int n = 6;
vector <vector<int>> matrix = {{   0,  4,  2,  6, -1,  3},  
                               {  -4, -2,  1,  9, -9,  2},  
                               {   2,  3,  1,  5, -5, -5},  
                               {   2,  4,  1,  0,  9, -1},  
                               { -10,  5,  1,  3,  4,  2},  
                               {  -2,  3,  8, -7,  1,  0}};

// printing given matrix to console
void print_matrix(vector<vector<int>> *matrix) {
	vector<vector<int>> :: iterator i;
	vector<int> :: iterator j;
	for (i = matrix->begin(); i != matrix->end(); i++) {
		for (j = i->begin(); j!= i->end(); j++) {
			cout.width(2);
			cout << *j << " ";
		}
		cout << endl;
	}
}

//deleting column from matrix
void delete_column(vector<vector<int>> *matrix, int column) {
	int i, j;
	int size_i = (*matrix).size();
	int size_j = (*matrix)[0].size();
	for (i=0; i<size_i; i++) {
		for (j=column; j<(size_j-1); j++) {
			(*matrix)[i][j] = (*matrix)[i][j+1];
		}
		(*matrix)[i].pop_back();
	}
}

int main () {
	
	print_matrix(&matrix);

	int i, j;
	int max_va, max_id;
	int min_va, min_id;
	max_id = 0;
	max_va = matrix[0][0];
	min_id = (n-1);
	min_va = matrix[0][n-1];
	for (i=0; i < n; i++) {
		
		// finding max 
		for (j=0; j<=i; j++) {
			if (matrix[i][j] > max_va) {
				max_va = matrix[i][j];
				max_id = j;
			}
		}
		
		// finding min
		for (j=(n-1); j>i; j--) {
			if (matrix[i][j] < min_va) {
				min_va = matrix[i][j];
				min_id = j;
			}
		}
	}
	
	cout << max_va << "\t" << max_id << endl;
	cout << min_va << "\t" << min_id << endl;
	delete_column(&matrix, max_id);
	delete_column(&matrix, min_id-1);
	print_matrix(&matrix);
	return 0;
}

//-----------------------------------------------//
// LEVEL 2
// TASK 23

#include <iostream>
#include <vector>

using namespace std;

const int stroke_len = 30;
const int max_amount = 5;

vector<vector<float>> matrix_a = {{  0,  3, -2,  2},
                                { -5, -6,  8,  8},  
                                { -2,  6,  0,  1},  
                                { -1, -2,  3, -4},  
                                {  9,  0, -9,  0}};
vector<vector<float>> matrix_b = {{ 1,  2,  3},  
                                {  0,  0,  0},  
                                { -1, -2, -3}};

template <typename type> 
void print_matrix(vector<vector<type>> *input_matrix) {
	for (int i=0; i<stroke_len; i++) {
		cout << "-";
	}
	cout<<endl;
	for (auto i = input_matrix->begin(); i!= input_matrix->end(); i++) {
		for (auto j = i->begin(); j!= i->end(); j++) {
			cout.width(7);
			cout << *j;
		}
		cout << endl;
	}
	for (int i=0; i<stroke_len; i++) {
		cout<<"-";
	}
	cout<<endl;
}


bool not_in_list(int (&list)[max_amount][2], int test_i, int test_j) {
	for (int i=0; i<max_amount; i++) {
		if (list[i][0] == test_i && list[i][1] == test_j) {
			return false;
		}	
	}
	return true;
}

template <typename type>
void find_first_max(int *max, int (&list)[max_amount][2], vector<vector<type>> *input_matrix, int pass) {
	for (int i=0; i<input_matrix->size(); i++) {
		for (int j=0; j<(*input_matrix)[0].size(); j++) {
			if (not_in_list(list, i, j)) {
				*max = (*input_matrix)[i][j];
				list[pass][0] = i;
				list[pass][1] = j;
				return;
			}	
		}
	}
	return;
}

template <typename type>
void find_max(int *max, int (&list)[max_amount][2], vector<vector<type>> *input_matrix, int pass) {
	for (int i=0; i<input_matrix->size(); i++) {
		for (int j=0; j<(*input_matrix)[0].size(); j++) {
			if ((*input_matrix)[i][j] > *max && not_in_list(list, i, j)) {
				*max = (*input_matrix)[i][j];
				list[pass][0] = i;
				list[pass][1] = j;
			}
		}
	}
	return;
}

template <typename type>
void mutate_matrix(vector<vector<type>> *input_matrix) {
	int max_ids[max_amount][2];
	int max = 0;
	for (int pass=0; pass<max_amount; pass++) {
		find_first_max(&max, max_ids, input_matrix, pass);
		find_max(&max, max_ids, input_matrix, pass);
	}
	for (int i=0; i<input_matrix->size(); i++) {
		for (int j=0; j<(*input_matrix)[0].size(); j++) {
			(*input_matrix)[i][j] /= 2;
		}
	}
	for (int i=0; i<max_amount; i++) {
		(*input_matrix)[max_ids[i][0]][max_ids[i][1]] *= 4;
	}
}

int main () {
	print_matrix(&matrix_a);
	print_matrix(&matrix_b);
	mutate_matrix(&matrix_a);
	print_matrix(&matrix_a);
	mutate_matrix(&matrix_b);
	print_matrix(&matrix_b);

    return 0;
}

//-----------------------------------------------//
// LEVEL 3
// TASK 1

#include <iostream>
#include <cmath>
#define PI 3.14
#define DELTA 0.0001

using namespace std;

template <typename type>
type function_a(type x, int i, int fact_i) {
	type y = (cos(x * i)) / fact_i;
	return y;
}

template <typename type>
type function_at(type x) {
	type y = exp(cos(x)) * cos(sin(x));
	return y;
}

template <typename type>
type function_b(type x, int i, int unused = 0) {
	type y = cos(i * x) / (i*i);
	if (i%2!=0) {
		y*=-1;
	}
	return y;
}

template <typename type>
type function_bt(type x) {
	type y = (x*x - PI*PI/3) / 4;
	return y;
}

float function_sum(float (*function)(float x, int i, int fact_i), float num) {
	float s = 0;
	int i = 1;
	int fact_i = 1;
	float x = function(num, i, fact_i);
	s += x;
	while (x>DELTA || x<-DELTA) {
		i++;
		fact_i *= i;
		x = function(num,i,fact_i);
		s += x;	
	}
	return s;	
}

int main() {
	
	for (float x=0.1; x<1+DELTA; x+= 0.1) {
		cout.width(16);
		cout << 1 + function_sum(function_a, x);
		cout.width(16);
		cout << function_at(x) << endl; 
	
	}
	for (int i=0; i<50; i++) {
		cout << "-";
	}
	cout << endl;
	for (float x=PI/5; x<PI; x+=PI/25) {
		cout.width(16);
		cout << function_sum(function_b, x);
		cout.width(16);
		cout << function_bt(x) << endl; 
	}
	return 0;
}

//-----------------------------------------------//
// LEVEL 3
// TASK 5

#include <iostream>
#include <cmath>
#define DELTA 0.0001


using namespace std;

float f1 (float x) {
	float y;
	y = x*x - sin(x);
	return y;
}

float f2 (float x) {
	float y;
	y = exp(x) - 1;
	return y;
}

int sign (float x) {
	if (x > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

int intervals (float (*f)(float x), float dx, float start, float end) {
	int result = 1;
	float x = start;
	float y = f(start);
	int last_sign = sign(y);
	while (x < end+DELTA) {
		x += dx;
		y = f(x);
		if (sign(y) != last_sign) {
			result++;
		}
		last_sign = sign(y);
	}
	return result;
}

int main () {
	cout << intervals(f1, 0.1, 0, 2) << endl;
	cout << intervals(f2, 0.1, -1, 1) << endl;	
}

//-----------------------------------------------//
// LEVEL 3
// TASK 6

#include <iostream>
#include <vector>

using namespace std;

const int n = 4;
vector<vector<int>> A = {{  3, -2, 10,  2},
					     {  1, 20,  3, -5},
					     {  0,  0,  1,  0},
						 {  2,  4, -4,  3}};

int find_max_col (vector<vector<int>> *matrix, int width) {
	int max = (*matrix)[0][0];
	int idx = 0;
	for (int i=1; i<width; i++) {
		if ((*matrix)[0][i] > max) {
			max = (*matrix)[0][i];
			idx = i;
		}
	}
	return idx;
}

int find_max_dig (vector<vector<int>> *matrix, int height) {
	int max = (*matrix)[0][0];
	int idx = 0;
	for (int i=1; i<height; i++) {
		if ((*matrix)[i][i] > max) {
			max = (*matrix)[i][i];
			idx = i;
		}
	}
	return idx;
}

template <typename mat = vector<vector<int>>>
void swap_col (int (*f1)(mat *matrix, int dim), int (*f2)(mat *matrix, int dim), mat *matrix, int dim) {
	int id_1 = f1(matrix, dim);
	int id_2 = f2(matrix, dim);
	cout << id_1 << " " << id_2 << endl;  
	int swap;
	for (int i=0; i<dim; i++) {
		swap = (*matrix)[i][id_1];
		(*matrix)[i][id_1] = (*matrix)[i][id_2];
		(*matrix)[i][id_2] = swap;
	}
}

void print_matrix(vector<vector<int>> *matrix, int dim) {
	for (int i=0; i<dim; i++) {
		for (int j=0; j<dim; j++) {
			cout << (*matrix)[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	
	print_matrix(&A, n);
	swap_col(find_max_col, find_max_dig, &A, n);
	print_matrix(&A, n);

}