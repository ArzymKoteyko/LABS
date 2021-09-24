#include <iostream>

using namespace std;

#include "matrix.h"


int main () {
	
	srand( time(0) );
	Matrix A(5);
	A.say_size();
	A.say_matrix();
	cout << A.get_matrix()[0][0] << "\n";

	return 0;

}
