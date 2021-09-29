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
    int len = 12;
    int i=0;
    while (i<len){
        if (A[i] < 0) {
            for (int j=i; j<11; j++) {
                A[j] = A[j+1];
            }
            len--;
        }
        else {
            i++;
        }
    }
    for (int i=0; i<len; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    return 0;
}
