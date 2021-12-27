#include <iostream>
#include <cmath>
#define DELTA 0.0001


using namespace std;

float f1 (float x) {
	float y;
	y = x*x - sin(x);
	return y;
}

float f2 (float x) {
	float y;
	y = exp(x) - 1;
	return y;
}

int sign (float x) {
	if (x > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

int intervals (float (*f)(float x), float dx, float start, float end) {
	int result = 1;
	float x = start;
	float y = f(start);
	int last_sign = sign(y);
	while (x < end+DELTA) {
		x += dx;
		y = f(x);
		if (sign(y) != last_sign) {
			result++;
		}
		last_sign = sign(y);
	}
	return result;
}

int main () {
	cout << intervals(f1, 0.1, 0, 2) << endl;
	cout << intervals(f2, 0.1, -1, 1) << endl;	
}
