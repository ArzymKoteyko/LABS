#include <iostream>
#include <algorithm>

using namespace std;

#include "matrix.h"
#include "queue.h"

void swap (int *a, int *b) {
		int buf = *a;
		*a = *b;
		*b = buf;
}

int** calc_mat (int size, int first_index, int second_index, int **source) {
	int **matrix = new int*[2];
	matrix[0] = new int[2];
	matrix[1] = new int[2];
	if (first_index > second_index) {
		swap(&first_index, &second_index);	
	}
	matrix[0][0] = source[size-2][first_index-1];
	matrix[0][1] = source[size-2][second_index-1];
	matrix[1][0] = source[size-1][first_index-1];
	matrix[1][1] = source[size-1][second_index-1];
	return matrix;
}

int calc_det (int **matrix) {
	int det;
	int main_diag = matrix[0][0] * matrix[1][1];
	int seco_diag = matrix[0][1] * matrix[1][0];
	det = main_diag - seco_diag;
	return det;
}

int iterate (Queue *used, Queue *left, Matrix *source) {
	if (left->get_size()>2) {
		int res = 0;
		Queue parity;
		for (int i=0; i<left->get_size(); i++) {
			used->append_back(left->pop_start());
			int mult = iterate(used, left, source);
			int col = used->get_queue()->ptr_back->value;
			int row = used->get_size();
			mult *= source->get_matrix()[row-1][col-1];
			res += mult;
			left->append_back(used->pop_back());
		}
		cout << left->get_size() << " " << res << "\n";
		return res;
	}
	else {
		int size = source->get_size();
		int first_index = left->get_queue()->ptr_next->value;
		int second_index = left->get_queue()->ptr_back->value;
		int **mat = calc_mat(size, first_index, second_index, source->get_matrix());
		int res = calc_det(mat);
		used->say_queue();
		left->say_queue();
		cout << left->get_size() << " " << res << "\n";
		return res;
	}
}

int main () {
	
	//srand( time(0) );
	srand(0);
	Matrix A(4);
	A.say_size();
	A.say_matrix();	
	Queue left_items;
	Queue used_items;
	for (int i=1; i<=4; i++) {
		left_items.append_back(i);
	}
	left_items.say_queue();
	used_items.say_queue();
	iterate(&used_items, &left_items, &A);

	return 0;

}






