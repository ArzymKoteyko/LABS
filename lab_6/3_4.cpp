#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int n = 4;
const int m = 4;

class Racer {
	public:
		
		string name;
		float time;

		Racer (string name_init, float time_init) {
			name = name_init;
			time = time_init;
		}

		void print () {
			cout.width(20);
			cout << name << " | time: " << time << endl; 
		}
};

void sort (Racer **group, int size) {
	 for (int i=0; i<size; i++) {
		int min_val = group[i]->time;
		int idx = i;
		for (int j=i; j<size; j++) {
			if (group[j]->time < min_val) {
				min_val = group[idx]->time;
				idx = j;
			}
		}
		Racer *swap = group[i];
		group[i] = group[idx];
		group[idx] = swap;
	 }
}

void print_group (Racer **group, int size, string name) {
	for (int i=0; i<50; i++) {
		cout << "-";
	}
	cout << endl;
	cout << name;
	cout << endl;
	for (int i=0; i<size; i++) {
		group[i]->print();
	}
}

int main () {

	Racer Vasya = Racer("Vasya", 21.3);
	Racer Andrey = Racer("Andrey", 18.9);
	Racer Timur = Racer("Timur", 17.4);
	Racer Pavel = Racer("Pavel", 17.63);
	Racer Vova = Racer("Vova", 23.12);
	Racer Vlad = Racer("Vlad", 22.3);
	Racer Sasha = Racer("Sasha", 19.98);
	Racer Gosha = Racer("Gosha", 35.2);

	Racer *G_A[n] = {&Vasya, &Andrey, &Timur, &Pavel};
	Racer *G_B[m] = {&Vova, &Vlad, &Sasha, &Gosha};

	Racer *Total[n+m];
	for (int i=0; i<n; i++) {
		Total[i] = G_A[i];
	}
	for (int i=0; i<m; i++) {
		Total[n+i] = G_B[i];
	} 
	
	print_group(G_A, n, "Group A");
	sort(G_A, n);
	print_group(G_A, n, "Group A");
	print_group(G_B, m, "Group B");
	sort(G_B, n);
	print_group(G_B, m, "Group B");
	print_group(Total, n+m, "Total");
	sort(Total, n+m);
	print_group(Total, n+m, "Total");

	return 0;

}
