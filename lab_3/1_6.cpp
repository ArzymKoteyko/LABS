#include <iostream>
#include <cmath>

using namespace std;

//int my_vector[5] = {1,1,1,1,1}; 			// square: 1	distance: 1 
//int my_vector[5] = {1,2,3,4,5}; 			// square: 55	distance: 7.4162
//int my_vector[5] = {-5,-4,-3,-2,-1}; 		// square: 55 	distance: 7.4162
int my_vector[5] = {5,-1,-4,3,4};			// square: 67	distance: 8.1853 

int main () {

	// printing my_vector cords
	cout << "Specified my_vector's cords: [ ";
	for (int i = 0; i < 5; i++) {
		cout << my_vector[i] << " ";
	}
	cout << "]\n";
	
	// calculating my_vector distance
	float sum = 0;
	float dist = 0;
	for (int i = 0; i < 5; i++) {
		sum += my_vector[i] * my_vector[i];
	}
	dist = pow(sum, 0.5);

	// printing results 
	cout << "Calculated distance: " << dist << "\n";
	return 0;
}
