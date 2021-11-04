#include <iostream>

using namespace std;

const int n = 7;
const int m = 9;
int A[n][m] = {{  3,  5, -3,  0, -3,  5,  6,  8,  0},  
               {  3,  4,  5,  2,  1, -3,  5,  9,  9},  
               { -2,  3, -1,  0,  0, -2, -3,  0, -8},  
               { -3, -2,  0,  0, -1,  9,  0,  0,  8},  
               {  3,  5,  2,  1,  3, -5,  1, -4,  2},  
               { -3,  2, -3,  0,  1,  1,  3,  5,  2},  
               { -3,  1,  3,  5,  2, -2, -3,  2,  1}};
int main() {
	int i,j,k;
	int del=0;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (i=0; i<n-del; i++) {
		for (j=0; j<m; j++) {
			if (A[i][j] == 0) {
				for (k=0; k<m; k++) {
					A[i][k] = A[n-del-1][k];
				}
				i--;
				del++;
				break;
			}
		}
	}

	for (i=0; i<n-del; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
