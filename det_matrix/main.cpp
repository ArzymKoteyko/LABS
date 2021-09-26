#include <iostream>

using namespace std;

#include "matrix.h"
#include "queue.h"

void iterate (Queue *used, Queue *left, Matrix *matrix) {
	if (left->get_size()>2) {
		for (int i=0; i<left->get_size(); i++) {
			used->append_back(left->pop_start());
			iterate(used, left, matrix);
			left->append_back(used->pop_back());
		}
	}
	else {
		used->say_queue();
		left->say_queue();
		for (int i=0; i<20; i++) {
			cout << "-";
		}
		cout <<"\n";
	}
}

int main () {
	
	srand( time(0) );
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






