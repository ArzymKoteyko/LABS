#include <iostream>
#include <random>
#include "matrix.h"

using namespace std;


Matrix::Matrix(int init_size) {
	
	set_size(init_size);
	set_matrix();
}


// actions with matrix_size
void Matrix::set_size(int new_size) {	
	matrix_size = new const int(new_size);
} 
int Matrix::get_size() {
	return *matrix_size;
}
void Matrix::say_size() {
	cout << "Matrix size is: " << *matrix_size << "\n";
}


// actions with matrix
void Matrix::malloc_matrix() {
	matrix = new int*[*matrix_size];
	for (int i=0; i < *matrix_size; i++) {
		matrix[i] = new int[*matrix_size];
	}
}
void Matrix::gen_matrix() {
	for (int i=0; i< *matrix_size; i++) {
		for (int j=0; j < *matrix_size; j++) {
			matrix[i][j] = rand()%10;
		}
	}
}
void Matrix::set_matrix() {
	malloc_matrix();
	gen_matrix();
}
int** Matrix::get_matrix() {
	return matrix;
}
void Matrix::say_matrix() {
	cout << "Matrix:\n";
	for (int i=0; i < *matrix_size; i++) {
		for (int j=0; j < *matrix_size; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}
