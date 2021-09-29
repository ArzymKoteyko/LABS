#include <iostream>

using namespace std;

int A[10] = {-1,-2, 3, 4, 5, 6, -2, -3, 7, 0};
int gr = 0;
int sh = 0;
int grm = 0;
int shm = 0;

int max (int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main () {
    for (int i=0; i<10; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    for (int i=1; i<10; i++) {
        if (A[i] > A[i-1]) {
            gr++;
        }
        else {
            if (gr > grm) {
                grm = gr;
            }
            gr = 0;
        }
        if (A[i] < A[i-1]) {
            sh++;
        }
        else {
            if (sh > shm) {
                shm = sh;
            }
            sh = 0;
        }
    }
    cout << max(grm, shm) << "\n"; 
    return 0;
}
