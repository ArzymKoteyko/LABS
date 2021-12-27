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
