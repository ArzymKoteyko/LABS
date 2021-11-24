#include <iostream>
#include <cmath>
#define PI 3.14
#define DELTA 0.0001

using namespace std;

template <typename type>
type function_a(type x, type i, type fact_i) {
	type y = (cos(x * i)) / fact_i;
	return y;
}

template <typename type>
type function_at(type x) {
	type y = exp(cos(x)) * cos(sin(x));
	return y;
}

template <typename type>
type function_b(type x, type i, type unused = 0) {
	type y = cos(i * x) / (i*i);
	return y;
}

template <typename type>
type function_bt(type x) {
	type y = (x*x - PI/3) / 4;
	return y;
}

float function_sum_a(float (*function)(float x, float i, float fact_i), float num) {
	float s = 0;
	float i = 1;
	float fact_i = 1;
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
	for (float a=0.1; a<1.0001; a+=0.1) {
		cout.width(4);
		cout << 1 + function_sum_a(function_a, a) << "\t" << function_at(a) << endl; 
	}
	return 0;
}
