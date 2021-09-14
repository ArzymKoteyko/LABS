#include <iostream>

using namespace std;

int main() {

	int nom_1   = 1;
	int nom_2   = 2;
	int nom_3;
	
	for (int i = 3; i <= 5; i ++) {
		nom_3 = nom_1 + nom_2;
		// for debug 
		//cout << nom_3 << "\t" << denom_3 << "\n";
		nom_1 = nom_2;
		nom_2 = nom_3;
	}
	cout << "Answer is: " << nom_2 << "/" << nom_1 << "\n";
	return 0;
}
