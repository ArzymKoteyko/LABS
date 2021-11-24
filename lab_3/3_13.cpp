#include <iostream>

using namespace std;

int A[10] = {1,2,3,4,5,6,7,8,9,10};
int first[5];
int second[5];

int main() {
    for (int i=0; i<10; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    for (int i=0; i<10/2; i++) {
        first[i] = A[i*2];
        second[i] = A[i*2+1];
    }
    /*
    for (int i=0; i<10; i++) {
         if (i%2==0) {
            first[i/2]=A[i];
         }
         else {
            second[(i-1)/2]=A[i];
         }
    }
    */
    for (int i=0; i<5;i++) {
        cout << first[i] << " ";
    }
    cout << "\n";
    for (int i=0; i<5;i++) {
        cout << second[i] << " ";
    }
    cout << "\n";
}
