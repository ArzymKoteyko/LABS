#include <iostream>

using namespace std;

int main() {
	
	int start_ammount = 10;
	int s = start_ammount;

	for (int i = 0; i <= 24; i += 3) {
		cout << "Hour : " << i << "\t";
		cout << "Ammount : " << s << "\n";
		s *= 2;
	}
	return 0;
}
