#include <iostream>
#include <cmath>

using namespace std;

//int vector[5] = {1,1,1,1,1}; 			// square: 1	distance: 1 
//int vector[5] = {1,2,3,4,5}; 			// square: 55	distance: 7.4162
//int vector[5] = {-5,-4,-3,-2,-1}; 		// square: 55 	distance: 7.4162
int vector[5] = {5,-1,-4,3,4};			// square: 67	distance: 8.1853 

int main () {

	// printing vector cords
	cout << "Specified vector's cords: [ ";
	for (int i = 0; i < 5; i++) {
		cout << vector[i] << " ";
	}
	cout << "]\n";
	
	// calculating vector distance
	float sum = 0;
	float dist = 0;
	for (int i = 0; i < 5; i++) {
		sum += vector[i] * vector[i];
	}
	dist = pow(sum, 0.5);

	// printing results 
	cout << "Calculated distance: " << dist << "\n";
	return 0;
}
