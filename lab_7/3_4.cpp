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

class Leage_Raccer : public Racer {

    public:

        string gender;
        string group;

        Leage_Raccer (string gender_init, string group_init, string name_init, float time_init) : Racer (name_init, time_init) {
            gender = gender_init;
            group = group_init;
        }

        void print() {
            cout.width(20);
			cout << gender << " " << name << " " << group << " | time: " << time << endl; 
        }
};

void sort (Leage_Raccer **group, int size) {
	 for (int i=0; i<size; i++) {
		int min_val = group[i]->time;
		int idx = i;
		for (int j=i; j<size; j++) {
			if (group[j]->time < min_val) {
				min_val = group[idx]->time;
				idx = j;
			}
		}
		Leage_Raccer *swap = group[i];
		group[i] = group[idx];
		group[idx] = swap;
	 }
}

void print_group (Leage_Raccer **group, int size, string name) {
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

	Leage_Raccer Vasya = Leage_Raccer ("male", "g1", "Vasya", 21.3);
	Leage_Raccer  Andrey = Leage_Raccer ("male", "g1",  "Andrey", 18.9);
	Leage_Raccer  Timur = Leage_Raccer ("male", "g2",  "Timur", 17.4);
	Leage_Raccer  Pavel = Leage_Raccer ("male", "g1",  "Pavel", 17.63);
	Leage_Raccer  Vova = Leage_Raccer ("male", "g3", "Vova", 23.12);
	Leage_Raccer  Vlad = Leage_Raccer ("male", "g3",  "Vlad", 22.3);
	Leage_Raccer  Sasha = Leage_Raccer ("male", "g2",  "Sasha", 19.98);
	Leage_Raccer  Gosha = Leage_Raccer ("male", "g1", "Gosha", 35.2);

	Leage_Raccer  *G_A[n] = {&Vasya, &Andrey, &Timur, &Pavel};
	Leage_Raccer  *G_B[m] = {&Vova, &Vlad, &Sasha, &Gosha};

	Leage_Raccer  *Total[n+m];
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