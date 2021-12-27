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
