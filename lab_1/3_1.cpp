#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define E 0.0001
#define LEFT_BORDER 0.1
#define RIGHT_BORDER 1.0001 
#define STEP 0.1

float row_sum (float x) {
	int i = 0;      // sum index
	int sine = 1;   // (-1)^i
	float fact = 1; // (2i)!
	float arg = 1;  //  whole sum
	float s = 0;    // total sum
	while (arg >= E || arg <= -E) {
		// first upadate sum and index
		s += arg;
		i += 1;
		
		// updating (-1)^i and (2i)! amd x^2i
		sine *= -1;
		fact *= (i * 2) - 1;
		fact *= (i * 2);
		if (i == 1) {
			x *= x;
		}
		else {
			x *= x * x;
		}
		// recanculate curent part
		arg = sine * (x/fact);
	}
	// now s is resault of cos(x)
	return s;
}

int main() {
	// Program output
	cout << "-----------------------------------------\n";
	cout << "ROW SUM\t\tCOS FUNC\tDELTA\n";
	for (float i = LEFT_BORDER; i <= RIGHT_BORDER; i += STEP) {
		cout << fixed 
		     << setprecision(6) 
		     << row_sum(i) << "\t" 
		     << cos(i) << "\t"
		     << row_sum(i) - cos(i) << "\n";
	}
	cout << "-----------------------------------------\n";
	return 0;
}


