#include <iostream>

using namespace std;

int main() {
	int p = 1;
	int n = 4;

	while (p < 30000) {
		p *= n;
		n += 3;
	} 

	cout << "Answer is: " << n - 6 << "\n";
	return 0;
}
