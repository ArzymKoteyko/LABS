#include <iostream>

using namespace std;

const int a_len_init = 7;
const int b_len_init = 8;

int a_len = a_len_init;
int b_len = b_len_init;

int A[a_len_init + b_len_init] = {1,-2,-3,4,-5,-6,-7,0,0,0,0,0,0,0,0};
int B[b_len_init] = {10,20,30,40,-50,60,-70,-80};

void del (int *array, int *len, int idx) {
	for (int i=idx; i<*len-1; i++) {
		array[i] = array[i+1];
	}
	*len -= 1;
}

void print_array (int *array, int *len) {
	for (int i=0; i<*len; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int max (int *array, int *len) {
	int idx = 0;
	int max = array[0];
	for (int i=0; i<*len; i++) {
		if (array[i] > max) {
			max = array[i];
			idx = i;
		}
	}
	return idx;
}

void concat(int *a_array, int *a_len, int *b_array, int *b_len) {
	for (int i=0; i<*b_len; i++) {
		a_array[i+(*a_len)] = b_array[i];
	}
	*a_len += *b_len;
}

int main() {
	print_array(A, &a_len);
	print_array(B, &b_len);
	del(A, &a_len, max(A, &a_len));
	del(B, &b_len, max(B, &b_len));
	concat(A, &a_len, B, &b_len);	

	print_array(A, &a_len);
	print_array(B, &b_len);

	return 0;
}
