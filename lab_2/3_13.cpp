#include <iostream>
#include <cmath>
#include <string>

using namespace std;

#define PI 3.1415926535 

string break_signal = "end";



float space_rect(float side_a, float side_b) {
	float total_space = side_a * side_b;
	return total_space;
}

float space_ring(float radius_a, float radius_b) {
	float total_space = (PI * radius_b * radius_b) - (PI * radius_a * radius_a);
	return total_space;
}

float space_trgl(float side_a, float side_b) {
	float p = (side_a + side_b + side_b) / 2;
	float total_space = pow(p * (p-side_a) * (p-side_b) * (p-side_b), 0.5);
	return total_space;
}



int main() {

	int n;
	float side_a, side_b;
	float space;
	string value;
	cout << "Methods: <rect> <ring> <trgl>\n";
	cout << "PLease enter ammount: ";
	cin >> n;
	for (int i=0; i<n; i++) {
		cout << "Enter sides length: ";
		cin >> value;
		if (value == break_signal) {
			break;
		}
		else {
			side_a = stof(value);
			cin >> side_b;
		}
		cout << "Enter calculation method: ";
		cin >> value;
		if (value == "rect") {
			space = space_rect(side_a, side_b);		
		}
		else if (value == "ring") {
			space = space_ring(side_a, side_b);
		}
		else if (value == "trgl") {
			space = space_trgl(side_a, side_b);
		}
		else {
			space = -1;
		}
		cout << "Result is: " << space << "\n";
	}
	return 0;
}

