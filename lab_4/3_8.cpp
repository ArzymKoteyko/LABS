#include <iostream>

using namespace std;

const int n = 7;
const int m = 5;

int A[n][m] = {{  3,  5, -3,  0, -3},  
               {  3,  4,  5,  2,  1},  
               { -2,  3, -1,  0,  0},  
               { -3, -2,  0,  0, -1},  
               {  3,  5,  2,  1,  3},  
               { -3,  2, -3,  0,  1},  
               { -3,  1,  3,  5,  2}};

int main() {
	int i,j,k;
	int max, pos_amount;
	int max_id;
	int buff;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	for (i=0; i<n; i++) {
		max = 0;
		max_id = i;
		for (j=i; j<n; j++) {
			pos_amount = 0;
			for (k=0; k<m; k++) {
				if (A[j][k] > 0) {
					pos_amount++;	
				}
			}
			if (pos_amount > max) {
				max = pos_amount;
				max_id = j;
			}
		}
		for (j=0; j<m; j++) {
			buff = A[i][j];
			A[i][j] = A[max_id][j];
			A[max_id][j] = buff;
		}
	}
	
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout.width(3);
			cout << A[i][j];
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
