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
	q.append_start(8);
	q.append_start(1);
	q.say_size();
	q.say_queue();
	cout << q.pop_start() << "\n";
	q.say_size();
	q.say_queue();
	q.pop_start();
	q.pop_start();
	q.say_size();
	q.say_queue();
	q.append_back(4);
	q.append_back(1);
	q.say_size();
	q.say_queue();
	q.pop_back();
	q.pop_back();
	q.append_back(87);
	q.say_size();
	q.say_queue();
	return 0;

}






