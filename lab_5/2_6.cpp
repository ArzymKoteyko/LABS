#include <iostream>
#include <vector>

using namespace std;

vector<int> A = {  0,  3, 13, -3, -2, 13,  0};
//vector<int> B = { 10,  2,  3, -2, -3, 10,  9,  8, 10};


int main() {
	vector<int> A;
	A.push_back(0);
	int i;
	int max = A[0];
	int n = A.size();
	for (i=0; i<A.size(); i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	for (i=0;i<n;i++) {
		if (A[i] == max) {
			A.erase(A.begin()+i, A.end()-n+i);
			n--;
			i--;
		}
	}
}
