// LEVEL 2
// TASK 5

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Command {

    public: 
        int score;
        int gol;
        int mis;
        string name;

        Command (string name_init) {
            name = name_init;
            score = 0;
            gol = 0;
            mis = 0;
        }
};

class Leage_Command : public Command {

    public:
        string home_stadium;
        string leage;

        Leage_Command(string name_init, string home_stadium_init, string leage_inti) : Command(name_init) {
            home_stadium = home_stadium_init;
            leage = leage_inti;
        }

};

void play(Command *team_a, Command *team_b, int a_score, int b_score) {
    if (a_score > b_score) {
        team_a->score = 3;
    }
    else if (b_score > a_score) {
        team_b->score += 3;        
    }
    else {
        team_a->score++;
        team_b->score++;
    }
}

int main () {

    Leage_Command CSK = Leage_Command("CSK", "Moscow", "Global");
    Command Manchester = Leage_Command("Manchester", "Liverpul", "Global");
    Command Dinamo = Leage_Command("Dinamo", "Moscow", "Russia");
    Command Zenit = Leage_Command("Zenit", "St-Piterburg", "Russia");
    Command Locomative = Leage_Command("Locomative", "Moscow", "Russia");

    play(&CSK, &Manchester, 0,1);
    cout << CSK.score << " " << Manchester.score << endl;

    return 0;
}

//------------------------------//
// LEVEL 3
// TASK 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
	public:

		string name;
		int subject_count;
		vector<int> score;
		float aver_score;

		Student (string init_name, int init_subject_count, vector<int> init_score) {
			name = init_name;
			subject_count = init_subject_count;
			score = init_score;
		}
		
		void calc_aver_score () {
			float score_sum = 0;
			for (int i=0; i<subject_count; i++) {
				score_sum += score[i];
			}
			aver_score = score_sum / subject_count;
		}

		float get_aver_score () {
			calc_aver_score();
			return aver_score;
		}

};

class Group {
	public:

		string group_name;
		int group_size;
		vector<Student> students;
		float aver_score;

		Group (string init_group_name, int init_group_size, vector<Student> init_students) {
			group_name = init_group_name;
			group_size = init_group_size;
			students = init_students;	
		}

		void calc_aver_score () {
			float score_sum = 0;
			for (int i=0; i<group_size; i++) {
				score_sum += students[i].get_aver_score();
			}	
			aver_score = score_sum / group_size;
		}

		float get_aver_score () {
			calc_aver_score();
			return aver_score;
		}
};

class Headmen : public Student {
    public: 
        string group;
        Headmen (string init_group, string init_name, int init_subject_count, vector<int> init_score) : Student(init_name, init_subject_count, init_score) {
            init_group = group;
        } 
};

int main() {
	
	Student Vasya = Student ("Vasya", 5, {1, 2, 3, 4, 5});
	Headmen Timur = Headmen ("G1", "Timur", 5, {5, 5, 5, 5, 5});
	Student Vanya = Student ("Vanya", 5, {5, 4, 5, 4, 5});
	Student Andrey = Student ("Andrey", 5, {3, 5, 2, 5, 4});
	Headmen Putin = Headmen ("G2", "Putin", 5, {3, 4, 2, 3, 1});
	Student Vova = Student ("Vova", 5, {3, 2, 3, 4, 3});

	cout << Vasya.get_aver_score() << " " << Timur.get_aver_score() << endl;
	cout << Vanya.get_aver_score() << " " << Andrey.get_aver_score() << endl;
	cout << Putin.get_aver_score() << " " << Vova.get_aver_score() << endl;

	Group G1 = Group ("G1", 2, {Vasya, Timur});
	Group G2 = Group ("G2", 2, {Vanya, Andrey});
	Group G3 = Group ("G3", 2, {Putin, Vova});

	cout << G1.get_aver_score() << endl;
	cout << G2.get_aver_score() << endl;
	cout << G3.get_aver_score() << endl;

	const int n = 3;
	vector<Group> groups = {G1,G2,G3};
	vector<float> group_score;
	for (int i=0; i<n; i++) {
		group_score.push_back(groups[i].get_aver_score());
	}
	for (int i=0; i<n; i++) {
		float max_aver = groups[i].get_aver_score();
		int max_idx = i;
		for (int j=i+1; j<n; j++) {
			if (groups[j].get_aver_score() > max_aver) {
				max_aver = groups[j].get_aver_score();
				max_idx = j;
			}
		}
		if (max_idx != i) {
			Group swap = groups[i];
			groups[i] = groups[max_idx];
			groups[max_idx] = swap;
		}
	}
	cout << "Номер группы" << "  |  " << "Средний балл" << endl;
	for (int i=0; i<n; i++) {
		cout.width(4);
		cout << groups[i].group_name;
		cout.width(11);
		cout << "|";
		cout.width(7);
		cout << groups[i].aver_score << endl;
	}


	return 0;

}

//------------------------------//
// LEVEL 3
// TASK 4

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