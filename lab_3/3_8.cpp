#include <iostream>

using namespace std;

int A[10] = {4,1,-10,-2,-4,0,23,-1,-3,-15};

void swap (int *a, int *b) {
    int buff = *a;
    *a = *b;
    *b = buff;
}

int main () {
    for (int i=0; i<10; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    for (int i=0; i<10; i++) {
        if (A[i] < 0) {
            int maxx = A[0];
            int max_id = -1;
            for (int j=i; j<10; j++) {
                if (A[j] < 0) {
                    if (A[j] > maxx) {
                        maxx = A[j];
                        max_id = j;
                    }
                }
            }
            swap(&A[i], &A[max_id]);
        }
    }
    for (int i=0; i<10; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    return 0;
}
