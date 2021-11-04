#include <iostream>

using namespace std;

const int n = 5;

/*
int A[n][n] = {{  4,  5, -3,  2,  4},
               {  0, -3, -4,  2,  3},  
               {  2,  3,  4,  5,  6},  
               { -2,  3,  4,  0,  0},  
               {  0,  0,  1,  0,  1}};
*/
int A[n][n] = {{  1,  1,  1,  1,  1},
               {  1,  1,  1,  1,  1},  
               {  1,  1,  1,  1,  1},  
               {  1,  1,  1,  1,  1},  
               {  1,  1,  1,  1,  1}};

template <typename type, int len> 
void print (type array[len][len]) {
	for (int i=0; i<len; i++) {
		for (int j=0; j<len; j++) {
			cout.width(3);
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	int i;
	print<int, n> (A);
	cout << endl;
	for (i=1; i<n-1; i++) {
		A[i][0] = 0;
		A[0][i] = 0;
		A[i][n-1] = 0;
		A[n-1][i] = 0;
	}
	A[0][0] = 0;
	A[0][n-1] = 0;
	A[n-1][0] = 0;
	A[n-1][n-1] = 0;
	print<int, n> (A);
	return 0;
}
