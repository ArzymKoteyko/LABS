#include <iostream>

using namespace std;

int maxs[10];
int A[10] = {2,-2,3,1,7,8,-10,8,7,8};
int c = 0;
int maxx = -1000000;

int main () {
    for (int i=0; i<10; i++) {
        if (A[i] > maxx) {
        c = 0;
        maxx = A[i];
        maxs[c] = i;
        c++;
        }
        else if (A[i] == maxx) {
            maxs[c] = i;
            c++;
        }
        cout << A[i] << " ";
    }
    cout << "\n";
    for (int i=0; i<c; i++) {
        cout << maxs[i] << " ";
    }
    cout << "\n";
    return 0;
}
