#include <iostream>

using namespace std;

int main() {
	float sine = -1;
	float pow  =  5;
	float fact =  1;
	float s    =  0;

	for (int i = 1; i <= 6; i++) {
		// For debug
		//cout << sine << "\t" << pow << "\t" << fact << "\n";
		s += (sine * pow) / fact;
		sine *= -1;
		pow *= 5;
		fact *= (i + 1); 
	}
	cout << "Answer is: " << s << "\n";
	return 0;
}
