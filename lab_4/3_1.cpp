#include <iostream>

using namespace std;

const int n = 7;
const int m = 5;
int matrix[n][m+1] = {{ -1,  3,  9,  1, -3,  0},
                      { -3, -5,  0,  3,  6,  0},
                      {  9,  6,  8,  9,  2,  0},
                      {  4,  4,  4,  3,  3,  0},
                      {  0,  1,  0, -1,  0,  0},
                      { -3, -2, -1,  0,  1,  0}, 
                      {  9,  8,  7,  6,  5,  0}};

int main(int argc, char *argv[]) {
    int i, j;
    
    for (i = 0; i<n; i++) {
        int min_value = matrix[i][0];
        cout.width(4);
        cout << matrix[i][0] << " ";
        for (j=1; j<m; j++) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
            }
            cout.width(4);
            cout << matrix[i][j] << " ";
        }
        matrix[i][m] = min_value;
        cout.width(4);
        cout << matrix[i][j] << " ";
        cout << endl;
    }

    for (i=0; i<n; i++) {
        int min_value = matrix[i][m];
        int min_id = i;
        for (j=i+1; j<n; j++) {
            
        }
    }


	return 0;
}
