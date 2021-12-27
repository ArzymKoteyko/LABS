#include <iostream>
#include <cmath>
#define PI 3.14
#define DELTA 0.0001

using namespace std;

template <typename type>
type function_a(type x, int i, int fact_i) {
	type y = (cos(x * i)) / fact_i;
	return y;
}

template <typename type>
type function_at(type x) {
	type y = exp(cos(x)) * cos(sin(x));
	return y;
}

template <typename type>
type function_b(type x, int i, int unused = 0) {
	type y = cos(i * x) / (i*i);
	if (i%2!=0) {
		y*=-1;
	}
	return y;
}

template <typename type>
type function_bt(type x) {
	type y = (x*x - PI*PI/3) / 4;
	return y;
}

float function_sum(float (*function)(float x, int i, int fact_i), float num) {
	float s = 0;
	int i = 1;
	int fact_i = 1;
	float x = function(num, i, fact_i);
	s += x;
	while (x>DELTA || x<-DELTA) {
		i++;
		fact_i *= i;
		x = function(num,i,fact_i);
		s += x;	
	}
	return s;	
}

int main() {
	
	for (float x=0.1; x<1+DELTA; x+= 0.1) {
		cout.width(16);
		cout << 1 + function_sum(function_a, x);
		cout.width(16);
		cout << function_at(x) << endl; 
	
	}
	for (int i=0; i<50; i++) {
		cout << "-";
	}
	cout << endl;
	for (float x=PI/5; x<PI; x+=PI/25) {
		cout.width(16);
		cout << function_sum(function_b, x);
		cout.width(16);
		cout << function_bt(x) << endl; 
	}
	return 0;
}
