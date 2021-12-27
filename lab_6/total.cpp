//LEVEL 2
//TASK 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
	public:

		string name;
		int amount = 4;
		vector<int> marks;
		float aver_mark;

		Student (string name_init, vector<int> marks_init) {
			name = name_init;
			marks = marks_init;
		}

		float get_aver_mark() {
			calc_aver_mark();
			return aver_mark;	
		}

	private:

		void calc_aver_mark() {
			float sum = 0;
			for (int i=0; i<amount; i++) {
				sum += marks[i];
			}	
			aver_mark = sum / amount;
		}
};

void sort_students(Student *students) {
	for (int i=0; i<4; i++) {
		float max_mark = students[i].get_aver_mark();
		int idx = i;
		for (int j=i+1; j<4; j++) {
			if (students[j].get_aver_mark() > max_mark) {
				max_mark = students[j].get_aver_mark();
				idx = j;
			}
		}
		Student swap = students[idx];
		students[idx] = students[i];
		students[i] = swap;
	}
}

void print_students(Student *students, bool show_all=false) {
	for (int i=0; i<20; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i=0; i<4; i++) {
		if (students[i].get_aver_mark() < 4 && show_all==false) { 
			break;
		}
		cout << students[i].name << "\t" << students[i].get_aver_mark() << endl;
	}
}

int main() {
	
	Student students[4] = {Student ("Vasya",  {3,5,5,5}),
						   Student ("Andrey", {3,3,3,4}),
						   Student ("Timur",  {4,5,4,4}),
						   Student ("Pavel",  {4,3,5,5})};

	print_students(students, true);
	sort_students(students);
	print_students(students);


	return 0;
}

//------------------------------------------------------//
// LEVEL 2
// TASK 2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
	public:

		string name;
		int amount = 4;
		vector<int> marks;
		float aver_mark;

		Student (string name_init, vector<int> marks_init) {
			name = name_init;
			marks = marks_init;
		}

		float get_aver_mark() {
			calc_aver_mark();
			return aver_mark;	
		}

	private:

		void calc_aver_mark() {
			float sum = 0;
			for (int i=0; i<amount; i++) {
				sum += marks[i];
			}	
			aver_mark = sum / amount;
		}
};

void sort_students(Student *students) {
	for (int i=0; i<4; i++) {
		float max_mark = students[i].get_aver_mark();
		int idx = i;
		for (int j=i+1; j<4; j++) {
			if (students[j].get_aver_mark() > max_mark) {
				max_mark = students[j].get_aver_mark();
				idx = j;
			}
		}
		Student swap = students[idx];
		students[idx] = students[i];
		students[i] = swap;
	}
}

void print_students(Student *students, bool show_all=false) {
	for (int i=0; i<40; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (students[i].marks[j] == 2 && show_all==false) {
				goto skip; 
			}
		}
		cout << students[i].name << "\t" << students[i].get_aver_mark() << "\t";
		for (int j=0; j<4; j++) {
			cout << students[i].marks[j] << ", ";
		}
		cout << endl;
		skip:;
	}
}

int main() {
	
	Student students[4] = {Student ("Vasya",  {4,5,5,5}),
						   Student ("Andrey", {2,3,3,4}),
						   Student ("Timur",  {4,5,4,4}),
						   Student ("Pavel",  {2,3,5,5})};

	print_students(students, true);
	sort_students(students);
	print_students(students);


	return 0;
}

//------------------------------------------------------//
// LEVEL 2
// TASK 5

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Team {
	public:

		string name;
		int score = 0;
		int goals = 0;
		int mis   = 0;

		Team (string name_init) {
			name = name_init;
		}
};

void play_game (Team *A_Team, Team *B_Team, int score_A, int score_B) {
	if (score_A > score_B) {
		A_Team->score += 3;
	}
	else if (score_A < score_B) {
		B_Team->score += 3;
	}
	else {
		A_Team->score++;
		B_Team->score++;
	}
	A_Team->goals += score_A;
	A_Team->mis += score_B;
	B_Team->goals += score_B;
	B_Team->mis += score_A;
}

void sort_teams (Team **teams) {
	for (int i=0; i<5; i++) {
		int max_score = teams[i]->score;
		int idx_max = i;
		for (int j=i; j<5; j++) {
			if (teams[j]->score > max_score) {
				max_score = teams[j]->score;
				idx_max = j;
			}
			else if (teams[j]->score == max_score) {
				if (teams[j]->goals - teams[j]->mis > teams[idx_max]->goals - teams[idx_max]->mis) {
					idx_max = j;
				}
			}
		}
		Team *swap = teams[idx_max];
		teams[idx_max] = teams[i];
		teams[i] = swap;
	}
}

void print_teams (Team **teams) {
	for (int i=0; i<5; i++) {
		cout.width(20);
		cout << teams[i]->name << " | total score: " << teams[i]->score << endl; 
	}
}

int main () {

	Team CSK       = Team ("CSK"); 
	Team Zenit     = Team ("Zenit");
	Team Locomativ = Team ("Locomativ");
	Team Zvezda    = Team ("Zvezda");
	Team Rubin     = Team ("Rubin");

	Team *commands[5] = {&CSK, &Zenit, &Locomativ, &Zvezda, &Rubin};
		
	print_teams(commands);
	for (int i=0; i<50; i++) {
		cout << "-";
	}
	cout << endl;

	play_game(&CSK, &Zenit, 3, 2);
	play_game(&Zenit, &Locomativ, 1, 1);
	play_game(&Locomativ, &Zvezda, 2, 3);
	play_game(&Zvezda, &Rubin, 5, 0);
	play_game(&CSK, &Locomativ, 1, 4);
	play_game(&Zenit, &Zvezda, 2, 2);
	play_game(&Rubin, &Zvezda, 0, 0);
	play_game(&CSK, &Rubin, 1, 1);

	print_teams(commands);
	for (int i=0; i<50; i++) {
		cout << "-";
	}
	cout << endl;

	sort_teams(commands);
	print_teams(commands);

	return 0;
}

//------------------------------------------------------//
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

int main() {
	
	Student Vasya = Student ("Vasya", 5, {1, 2, 3, 4, 5});
	Student Timur = Student ("Timur", 5, {5, 5, 5, 5, 5});
	Student Vanya = Student ("Vanya", 5, {5, 4, 5, 4, 5});
	Student Andrey = Student ("Andrey", 5, {3, 5, 2, 5, 4});
	Student Putin = Student ("Putin", 5, {3, 4, 2, 3, 1});
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

//------------------------------------------------------//
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

//------------------------------------------------------//
// LEVEL 3
// TASK 6

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Answer {
	string animal;
	string trait;
	string item;
};

class Category {
	public:
		
        string name;
		vector<string> variants;
		vector<int> variants_counter;
		int total_answers = 0;

		Category (string name_init) {
            this->name = name_init;
        }

		void add_answer (string new_answer) {
			total_answers++;
			for (int i=0; i<variants.size(); i++) {
				if (new_answer == variants[i]) {
					variants_counter[i] += 1;
					return;
				}
			}
			variants.push_back(new_answer);
			variants_counter.push_back(1);
		}

		void sort_answers () {
			for (int i=0; i<variants.size(); i++) {
				int most_common = variants_counter[i];
				int  most_common_idx = i;
				for (int j=i+1; j<variants.size(); j++) {
					if (variants_counter[j] > most_common) {
						most_common = variants_counter[j];
						most_common_idx = j;
					}
				}
				if (most_common_idx != i) {
					int swap_amount = variants_counter[most_common_idx];
					variants_counter[most_common_idx] = variants_counter[i];
					variants_counter[i] = swap_amount;

					string swap  = variants[most_common_idx];
					variants[most_common_idx] = variants[i];
					variants[i] = swap;
				}
			}
		}
};

class Pull {
    public:
        Category *categories[3];
        int total_answers = 0;
        Pull() {
            categories[0] = new Category("Animals");
            categories[1] = new Category("Traits");
            categories[2] = new Category("Items");
        }

        void add_answer (Answer new_answer) {
			total_answers++;
			categories[0]->add_answer(new_answer.animal);
            categories[1]->add_answer(new_answer.trait);
            categories[2]->add_answer(new_answer.item);
		}

        void sort_pull () {
            for (int i=0; i<3; i++) {
                categories[i]->sort_answers();
            }
        }

        void print() {
            int max_lenght = 0;
            for (int i=0; i<3; i++) {
                if (categories[i]->variants_counter.size() > max_lenght) {
                    max_lenght = total_answers;
                }
            }
            for (int i=0; i<total_answers; i++) {
                for (int j=0; j<3; j++) {
					
                    if (i < categories[j]->variants_counter.size()) {
						cout.width(13);
                        cout << categories[j]->variants[i] << " : " << int(float(categories[j]->variants_counter[i])/categories[j]->total_answers*100) << "% | ";
                    }
                    else {
						for (int s=0; s<22; s++) {
                        	cout << " ";
						}
                    }
                    
                }
				cout << endl;
            }
        }
};

int main () {
	Pull my_pull = Pull();
	Answer a;
	a.animal = "Tanuki"; a.trait = "empatic"; a.item = "loli";
	my_pull.add_answer(a);
	a.animal = "Kidsi"; a.trait = "hardworking"; a.item = "anime";
	my_pull.add_answer(a);
	a.animal = "Tanuki"; a.trait = "empatic"; a.item = "sinkansen";
	my_pull.add_answer(a);
	a.animal = "Tanuki"; a.trait = "social"; a.item = "nisan";
	my_pull.add_answer(a);
	a.animal = "Kidsi"; a.trait = "lonely"; a.item = "sushi";
	my_pull.add_answer(a);
	a.animal = "Dear"; a.trait = "hardworking"; a.item = "sushi";
	my_pull.add_answer(a);
	a.animal = "Tanuki"; a.trait = "naturalistic"; a.item = "nuclear bomb";
	my_pull.add_answer(a);

	my_pull.sort_pull();
	my_pull.print();
	cout << endl;
	
	return 0;
}
