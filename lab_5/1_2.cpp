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
