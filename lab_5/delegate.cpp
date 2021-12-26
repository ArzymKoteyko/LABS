#include <iostream>

using namespace std;

int square (int n) {
	return n * n;
}

int cube (int n) {
	return n * n * n;
}

int function_sum (int n, int (*f1)(int n), int (*f2)(int n)) {
	return f1(n) + f2(n);
}

int main() {
	int a;
	cin >> a;
	cout << function_sum(a, square, cube); 
	return 0;
}
