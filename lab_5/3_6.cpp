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
