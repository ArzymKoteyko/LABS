#include <iostream>

using namespace std;

int A[10] = {0,5,-3,-3,4,2,10,13,8,1};

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
    for (int i=0; i<10; i+=2) {
        int minn = A[0];
        int min_id = -1;
        for (int j=i; j<10; j+=2) {
            if (A[j] <= minn) {
                minn = A[j];
                min_id = j; 
            }
        }
        swap(&A[i], &A[min_id]);
    }
    for(int i=0; i<10; i++) {
        cout << A[i] << " ";
    } 
    cout << "\n";
    return 0;
}
