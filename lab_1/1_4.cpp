#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265

int main() {
	float x;
	
	cout << "Enter x in degrees:\n";
	cin >> x;
	x = x * PI / 180;
	
	float s = 0;
	float pow = 1;

	for (int i = 1; i <= 9; i++) {
		// For debug
		//cout << pow << "\t" << x * i << "\t";
		s += cos(x * i) / pow;
		// For debug
		//cout << s << "\n";
		pow *= x;
	}
	cout << "Answer is: ";
	cout << s << "\n";
	return 0;
}
