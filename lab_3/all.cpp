#include <iostream>
#include <cmath>

using namespace std;

int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int P = 3;
int Q = 8;

int main () {
	
	// printing specified cords
	cout << "Specified A's items: [ ";
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	cout << "]\n";
	cout << "P: " << P << "\tQ: " << Q << "\n";
	
	// counting and printing elemnts in range (P;Q)
	int counter = 0;
	for (int i = 0; i < 10; i++) {
		if (A[i] > P && A[i] < Q) {
			cout << A[i] << " ";
			counter++;
		}
	}

	// printing result
	cout << "\nAmount of items in given range: " << counter << "\n";
	return 0;
}
#include <iostream>

using namespace std;

//int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};			// res: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//int A[10] = {-1, 2, -3, 4, -5, 6, -7, 8, -9, 10};			// res: [2, 4, 6, 8, 10]
int A[10] = {-1, -2, -4, -5, 6, 7, 8, -10, 12, 13};			// res: [6, 7, 8, 12, 13]
int main () {
	
	
	// printing specified A
	cout << "Specified A's items: [ ";
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	cout << "]\n";
	
	// calculating new A size 
	int item_count = 0;
	for (int i = 0; i < 10; i++) {
		if (A[i] > 0) {
			item_count++;
		}
	}

	// creating new A
	int res[item_count];
	item_count = 0;
	for (int i = 0; i < 10; i++) {
		if (A[i] > 0) {
			res[item_count] = A[i];
			item_count++;
		}
	}


	// printing result
	cout << "Array of positive elements: [ ";
	for (int i = 0; i < item_count; i++) {
		cout << res[i] << " ";
	}
	cout << "]\n";
	return 0;
}
#include <iostream>

using namespace std;

int A[8] = {-1, -2, 4, 3, -6, 3, 0, 1}; 		// res -> index: 4 value: -6
//int A[8] = {0, -1, -2, -3, -4, -5, -6, 0}; 		// res -> index: 6 value: -6
//int A[8] = {0, 1, 0, 1, 0, 1, 2, 3}; 		// res -> NONE
int main () {
	
	// printing specified A
	cout << "Specified A's items: [ ";
	for (int i = 0; i < 8; i++) {
		cout << A[i] << " ";
	}
	cout << "]\n";
	
	// calculating index and value of last negative element
	int index = -1;
	int value;
	bool find = false;
	for (int i = 0; i < 8; i++) {
		if (A[i] < 0) {
			index = i;
			value = A[i];
			find = true;
		}
	}

	// printing result
	if (find) {
		cout << "last index: " << index << "\t\tvalue: " << value << "\n";
	}
	else {
		cout << "all elements are NON-negative\nlast index: NONE\tvalue: NONE\n";
	}
	return 0;
}
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // res -> [0, 2, 4, 6, 8] | [1, 3, 5, 7, 9]

int main () {

	// printing specified A
	cout << "Specified A's items: [ ";
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	cout << "]\n";

	// calculating new odd and even As
	int odd[5];
	int even[5];

	for (int i = 0; i < 10/2; i++) {
        even[i] = A[i*2];
		odd[i] = A[i*2+1];
	}

	// printing even A
	cout << "Specified even A's items: [ ";
	for (int i = 0; i < 5; i++) {
		cout << even[i] << " ";
	}
	cout << "]\n";

	// printing odd A
	cout << "Specified odd A's items: [ ";
	for (int i = 0; i < 5; i++) {
		cout << odd[i] << " ";
	}
	cout << "]\n";

	return 0;
}
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
#include <iostream>

using namespace std;

int my_array[10] = {-1,-3,2,8,9,7,-2,13,4,3};
int minn = my_array[0];
int min_id = -1;

int main () {
	for (int i=0; i<10; i++) {
		cout << my_array[i] << " ";
		if (my_array[i]>0 && my_array[i]<minn) {
			minn = my_array[i];
			min_id = i;
		}
	}
	cout << "\n";
	cout << minn << " " << min_id << "\n";
	int *new_my_array = new int[9];
	int c = 0;
	while (c < min_id) {
		new_my_array[c] = my_array[c];
		c++;
	}
	c++;
	for(int i=c; i<10;i++) {
		new_my_array[i-1]=my_array[i];
	}
	for (int i=0; i<9;i++) {
		cout << new_my_array[i] << " ";
	}
	cout << "\n";
	return 0;
}
#include <iostream>

using namespace std;

int my_array[10] = {-1,-3,2,8,9,7,-2,-13,-4,-3};
int P = 100;
int last_id = -1;

int main () {
	for (int i=0; i<10; i++) {
		cout << my_array[i] << " ";
		if (my_array[i] > 0) { 
			last_id=i;
		}
	}
	cout << "\n";

	int *new_my_array = new int[11];
	for (int i=0; i<last_id+1;i++) {
		new_my_array[i] = my_array[i];
	}
	new_my_array[last_id+1] = P;
	for (int i=last_id+2; i<11; i++) {
		new_my_array[i] = my_array[i-1];
	}

	for (int i=0; i<11; i++) {
		cout << new_my_array[i] << " ";
	}
	cout << "\n";
	return 0;
}
#include <iostream>

using namespace std;

int my_array[10] = {-1,-3,2,8,9,7,-2,-13,-4,-3};

int maxx = my_array[0];
int max_id = -1;

int main () {
    for (int i=0; i<10; i++) {
        cout << my_array[i] << " ";
    }
    cout << endl;
	for (int i=0; i<10/2; i++) {
		if (my_array[i*2] > maxx) {
			maxx = my_array[i*2];
			max_id = i*2;
		}
	}
	
	my_array[max_id] = max_id;
	for (int i=0; i<10; i++) {
		cout << my_array[i] << " ";
	}
	cout << "\n";
	return 0;
}
#include <iostream>

using namespace std;

const int n = 8;
const int m = 6;
int A[n+m] = {-1,-2,-3,-4,-5,-6,-7,-8,0,0,0,0,0,0};
int B[n] = {1,2,3,4,5,6};
int k = 4;

int main () {
	for (int i=0; i<n; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	for (int i=0; i<m; i++) {
		cout << B[i] << " ";
	}
	cout << "\n";
	cout << "k: " << k << "\n";
    for (int i=n+m-1; i>k; i--) {
        A[i] = A[i-k-1];
    }
    int j = 0;
    for (int i=k; i<k+m; i++) {
        A[i] = B[j];
        j++;
    }
    for (int i=0; i<n+m; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    /*	
	int *C = new int[6+8]; 
	
	for (int i=0; i<k; i++) {
		C[i] = A[i];
	}
	for (int i=k; i<k+6; i++) {
		C[i] = B[i-k];
	}
	for (int i=k+6; i<6+8; i++) {
		C[i] = A[i-6];
	}

	for (int i=0; i<8+6; i++) {
		cout << C[i] << " ";
	}
	cout << "\n";
    */
	return 0;
}
#include <iostream>

using namespace std;

int my_array[10] = {-1,-3,2,8,9,7,-2,13,4,3};
int maxx = my_array[0];
int minn = my_array[0];
int max_id = -1;
int min_id = -1;

int main () {
	
	for (int i=0; i<10; i++) {
		cout << my_array[i] << " ";
	}
	cout << "\n";
	
	for (int i=0; i<10; i++) {
		if (my_array[i] < minn) {
			minn = my_array[i];
			min_id = i;
		}
		if (my_array[i] > maxx) {
			maxx = my_array[i];
			max_id = i;
		}
	}
	cout << min_id << " " << max_id << "\n";
	
	if (max_id < min_id) {
		int s = max_id;
		max_id = min_id;
		min_id = s;
	}

	int *new_my_array = new int[max_id-min_id-1];
	for (int i=0; i<max_id-min_id-1; i++) {
		new_my_array[i] = my_array[i+min_id+1];
		cout << new_my_array[i] << " ";
	}
	cout << "\n";

	return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int A[10] = {1,0,5,4,20,3,-2,13,-8,7};
int P = 100;

float average (int *array, int len) {
	float res = 0;
	for (int i=0; i<len; i++) {
		res += array[i];
	}
	res = res/len;
	return res;
}

int main () {
	for (int i=0; i<10; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	int ave = average(A, 10);
	int dif = fabs(A[0]-ave);
	int id = -1;
	for (int i=0; i<10; i++) {
		if (fabs(A[i]-ave) < dif) {
			dif = fabs (A[i]-ave);
			id = i;
		}
	}
	cout << ave << " " << dif << " " << id << "\n";
	int *new_array = new int[11];
	int c = 0;
	while (c <= id) {
		new_array[c] = A[c];
		c++;
	}
	new_array[c] = P;
	c++;
	for (int i=c; i<11;i++) {
		new_array[i] = A[i-1];
	}
	for (int i=0; i<11; i++) {
		cout << new_array[i] << " ";
	}
	cout << "\n";
	return 0;

}
#include <iostream>

using namespace std;

int my_array[10] = {-1,-3,2,8,9,7,-2,13,4,3};
int maxx = my_array[0];
int minn =  my_array[0];
int max_id = -1;
int min_id = -1;

int main () {

	for (int i=0; i<10; i++) {
		cout << my_array[i] << " ";
	}
	cout << "\n";
	
	for (int i=0; i<10; i++) {
		if (my_array[i] < minn) {
			minn = my_array[i];
			min_id = i;
		}
		if (my_array[i] > maxx) {
			maxx = my_array[i];
			max_id = i;
		}
	}
	cout << min_id << " " << max_id << "\n";
	
	if (max_id < min_id) {
		int s = max_id;
		max_id = min_id;
		min_id = s;
	}
		
	float average = 0;
	int c = 0;
	for (int i=min_id+1; i<max_id; i++) {
		average += my_array[i];
		c++;
	}
	average /= c;
	cout << "Average: " << average << "\n";

	return 0;
}
#include <iostream>

using namespace std;

int maxs[10];
int A[10] = {2,-2,3,1,7,8,-10,8,7,8};
int c = 0;
int maxx = A[0];

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
#include <iostream>

using namespace std;

int A[10] = {0,5,-3,-3,4,2,10,13,8,1};

void swap (int *a, int *b) {
    int buff = *a;
    *a = *b;
    *b = buff;
}

int main () {
    for (int i=0; i<10; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    for (int i=0; i<10; i+=2) {
        int minn = A[0];
        int min_id = -1;
        for (int j=i; j<10; j+=2) {
            if (A[j] <= minn) {
                minn = A[j];
                min_id = j; 
            }
        }
        swap(&A[i], &A[min_id]);
    }
    for(int i=0; i<10; i++) {
        cout << A[i] << " ";
    } 
    cout << "\n";
    return 0;
}
#include <iostream>

using namespace std;

int A[10] = {4,1,-10,-2,-4,0,23,-1,-3,-15};

void swap (int *a, int *b) {
    int buff = *a;
    *a = *b;
    *b = buff;
}

int main () {
    for (int i=0; i<10; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    for (int i=0; i<10; i++) {
        if (A[i] < 0) {
            int maxx = A[0];
            int max_id = -1;
            for (int j=i; j<10; j++) {
                if (A[j] < 0) {
                    if (A[j] > maxx) {
                        maxx = A[j];
                        max_id = j;
                    }
                }
            }
            swap(&A[i], &A[max_id]);
        }
    }
    for (int i=0; i<10; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    return 0;
}
#include <iostream>

using namespace std;

int A[10] = {-1,-2, 3, 4, 5, 6, -2, -3, 7, 0};
int gr = 0;
int sh = 0;
int grm = 0;
int shm = 0;

int max (int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main () {
    for (int i=0; i<10; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    for (int i=1; i<10; i++) {
        if (A[i] > A[i-1]) {
            gr++;
        }
        else {
            if (gr > grm) {
                grm = gr;
            }
            gr = 0;
        }
        if (A[i] < A[i-1]) {
            sh++;
        }
        else {
            if (sh > shm) {
                shm = sh;
            }
            sh = 0;
        }
    }
    cout << max(grm, shm) << "\n"; 
    return 0;
}
