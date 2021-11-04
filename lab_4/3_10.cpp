#include <iostream>

using namespace std;

const int n = 7;
const int m = 9;

int A[n][m] = {{  3,  5, -3,  0, -3,  5,  6,  8,  0},  
               {  3,  4,  5,  2,  1, -3,  5,  9,  9},  
               { -2,  3, -1,  0,  0, -2, -3,  0, -8},  
               { -3, -2,  0,  0, -1,  9,  0,  0,  8},  
               {  3,  5,  2,  1,  3, -5,  0, -4,  2},  
               { -3,  2, -3,  0,  1,  1,  3,  5,  2},  
               { -3,  1,  3,  5,  2, -2, -3,  2,  0}};
int main() {
	int i,j,k;
	int min_odd, max_even;
	int min_id, max_id;
	int buff;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (i=0; i<n; i++) {
		for (j=0; j<m/2; j++) {
			
			min_odd  = A[i][j*2+1];
			max_even = A[i][j*2];
			min_id = j*2+1;
			max_id = j*2;
			
			for (k=j; k<m/2; k++) {
				if (A[i][k*2] > max_even) {
					max_even = A[i][k*2];
					max_id = k*2;
				}
				if (A[i][k*2+1] < min_odd) {
					min_odd = A[i][k*2+1];
					min_id = k*2+1;
				}
			}
			if (m%2==1 && A[i][m-1] > max_even) {
				max_even = A[i][m-1];
				max_id = m-1;
			}

			buff = A[i][min_id];
			A[i][min_id] = A[i][j*2+1];
			A[i][j*2+1] = buff;

			buff = A[i][max_id];
			A[i][max_id] = A[i][j*2];
			A[i][j*2] = buff;
		}
	}
	
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	return 0;
}
