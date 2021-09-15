#include <iostream>
#include <cmath>
#include <string>

using namespace std;

#define PI 3.1415926535 

string break_signal = "end";



float space_square(float side) {
	float total_space = side * side;
	return total_space;
}

float space_circle(float radius) {
	float total_space = PI * radius * radius;
	return total_space;
}

float space_triangle(float side) {
	float total_space = pow(3, 0.5) / 4 * side * side;
	return total_space;
}



int main() {

	int n;
	float side;
	float space;
	string value;
	cout << "Methods: <square> <circle> <triangle>\n";
	cout << "PLease enter ammount: ";
	cin >> n;
	for (int i=0; i<n; i++) {
		cout << "Enter side length: ";
		cin >> value;
		if (value == break_signal) {
			break;
		}
		else {
			side = stof(value);	
		}
		cout << "Enter calculation method: ";
		cin >> value;
		if (value == "square") {
			space = space_square(side);		
		}
		else if (value == "circle") {
			space = space_circle(side);
		}
		else if (value == "triangle") {
			space = space_triangle(side);
		}
		else {
			space = -1;
		}
		cout << "Result is: " << space << "\n";
	}
	return 0;
}
