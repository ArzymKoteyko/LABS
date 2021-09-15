#include <iostream>
#include <iomanip>

using namespace std;

#define GRAIN_TO_GRAMS 0.06666666

int main() {
	unsigned long int s = 0;
	unsigned long int on_cell = 1;
	for (int i = 0; i < 64; i++) {
		// For debug
		//cout << s << "\n";
		s += on_cell;
		on_cell *= 2;
	}
	cout << "Answer is: "
	     << s 
	     << "\n" 
	     << fixed 
	     << setprecision(4)
	     << s * GRAIN_TO_GRAMS / 1000 / 1000 / 1000 / 1000 
	     << " Mtons\n"; 
}
