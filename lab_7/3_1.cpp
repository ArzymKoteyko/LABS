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