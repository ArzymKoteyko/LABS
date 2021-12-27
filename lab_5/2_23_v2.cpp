#include <iostream>
#include <vector>

using namespace std;

const int n = 4;
const int m = 5;
int n_dyn = n;
int m_dyn = m;


vector<vector<int>> A = {{ 10, -4,  3, 23, -3},
						 { -2,  3, 10,-20,-21},
						 { 10,  2,  2,  8, -2},
						 { -4, -5,  3,  5,  2}};


int find_max (vector<vector<int>> *matrix, int *height, int *width) {
	int max_val = (*matrix)[0][0];
	for (int i=0; i<*height; i++) {
		for (int j=0; j<*width; j++) {
			if ((*matrix)[i][j] > max_val) {
				max_val = (*matrix)[i][j];
			}
		}
	}
	return max_val;
}

int find_max_cond (vector<vector<int>> *matrix, int *height, int *width, int mark) {
	int max_val;
	int max_i;
	int max_j;
	for (int i=0; i<*height; i++) {
		for (int j=0; j<*width; j++) {
			if ((*matrix)[i][j] % mark != 0) {
				max_val = (*matrix)[i][j];
				max_i = i;
				max_j = j;
				break;
			}
		}
	}
	for (int i=0; i<*height; i++) {
		for (int j=0; j<*width; j++) {
			if ((*matrix)[i][j] > max_val && (*matrix)[i][j] % mark != 0) {
				max_val = (*matrix)[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	(*matrix)[i][j] *= mark;
}

int main () {
	cout << find_max(&A, &n_dyn, &m_dyn);

	return 0;
}
