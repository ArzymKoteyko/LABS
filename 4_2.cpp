#include <iostream>

#define E 0.0001

using namespace std;

float x;

bool corect(float num) {
	if (num > -1 && num < 1) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	cout << "Enter value of x: ";
	cin >> x;
	if (!corect(x)) {
		while (!corect(x)) {
			cout << "Try again: ";
			cin >> x;
		}
	}
	
	float s = 1;
	x *= x;
	while (x >= E) {
		s += x;
		x *= x * x;
	}
	cout << "Answer: " << s << "\n";
	return 0;
}
