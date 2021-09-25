#include <iostream>

using namespace std;

#include "matrix.h"
#include "queue.h"

int main () {
	
	srand( time(0) );
	Matrix A(4);
	A.say_size();
	A.say_matrix();

	Queue q;
	q.append_start(3);
	q.append_start(5);
	q.append_start(2);
	q.say_size();
	q.say_queue();

	return 0;

}






