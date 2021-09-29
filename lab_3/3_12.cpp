#include <iostream> 

using namespace std; 

int A[12] = {0,-1,-2,3,4,-5,-6,-7,8,9,10,-11};

void swap (int *a, int *b) {
    int buff = *a;
    *a = *b;
    *b = buff;
}

int main () {
    for (int i=0; i<12; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    int c = 0;
    int len = 12;
    while (c < len) {
        if (A[c] < 0) {
            swap(A[c], A[len-1]);
            A[len-1] = 0;
            len--;
        }
        else {
            c++;
        }
    }
    
    for (int i=0; i<12; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    return 0;
}
