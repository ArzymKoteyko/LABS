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


