#include <iostream>

using namespace std;

int fact(int x) {
	int res = 1;
	if (x == 0) {
		return 1;
	}
	for (int i=1; i<=x; i++) {
		res *= i;
	}
	return res;
}

int permutation(int k, int n) {
	return fact(n) / (fact(k) * fact(n - k));
}


int main () {
	cout << permutation(5, 8) << endl;
	cout << permutation(5, 10) << endl;
	cout << permutation(5, 11) << endl;
	return 0;
}
