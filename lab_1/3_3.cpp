#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define DELTA 0.0001
#define E 2.71828182845904
#define LEFT_BORDER 0.1
#define RIGHT_BORDER 1.0001
#define STEP 0.1

float row_sum(float x) {
	int i = 1;
	float s = 0;
	float fact = 1;
	float arg = cos(x * i) / fact;
	while (arg >= DELTA || arg <= -DELTA) {
		s += arg;
		i += 1;
		fact *= i;
		arg = cos(x * i) / fact;
	}
	return s;
}

int main() {
	cout << "-----------------------------------------\n";
	cout << "ROW SUM\t\tFUNC\t\tDELTA\n";
	for (float i = LEFT_BORDER; i <= RIGHT_BORDER; i+= STEP) {
		cout << fixed
		     << setprecision(6)
		     << row_sum(i) << "\t"
		     << pow(E,cos(i))*cos(sin(i)) << "\t"
		     << row_sum(i) - pow(E,cos(i))*cos(sin(i)) << "\n";
	}
	cout << "-----------------------------------------\n";
	return 0;
} 
