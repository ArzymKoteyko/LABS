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
