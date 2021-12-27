#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string float_to_string (float num, int precision = 2) {
	stringstream conversion;
	conversion << fixed;
	conversion << setprecision(precision);
	conversion << num;
	string result = conversion.str();
	return result;
}

struct Answer {
	string animal;
	string trait;
	string item;
};

class Category {
	public:
		
		vector<string> variants;
		vector<int> variants_counter;
		int total_answers = 0;

		Category () {
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
		Category animal = Category();
		Category trait  = Category();
		Category item   = Category();
		
		Pull () {
		}

		void add_answers_to_pull (Answer new_answer) {
			animal.add_answer(new_answer.animal);
			trait.add_answer(new_answer.trait);
			item.add_answer(new_answer.item);
		}

		string create_field(int variant_lenght, int count_lenght, string *variant, int count, float percent) {
			string result;
			for (int i=0; i<variant_lenght - variant->size(); i++) {
				result += " ";
			}
			result += *variant;
			result += " : ";
			result += to_string(count);
			int lenght = to_string(count).size();;
			for (int i=0; i<count_lenght - lenght; i++) {
				result += " ";
			}
			result += " : ";
			result += float_to_string(percent);
			result += "% |";
			return result;
		}
		
		void print_line(int idx) {
			if (idx < animal.variants.size()) { 
				cout << create_field(10, 2, &animal.variants[idx], animal.variants_counter[idx], float(animal.variants_counter[idx]) / animal.total_answers * 100);
			}
			else {
				for (int i=0; i<10+2+3+3+8; i++) {
					cout << " ";
				}
			}
			if (idx < trait.variants.size()) {
				cout << create_field(10, 2, &trait.variants[idx], trait.variants_counter[idx], float(trait.variants_counter[idx]) / trait.total_answers * 100);
			}
			else {
				for (int i=0; i<10+2+3+3+8; i++) {
					cout << " ";
				}
			}
			if (idx < item.variants.size()) {
				cout << create_field(10, 2, &item.variants[idx], item.variants_counter[idx], float(item.variants_counter[idx]) / item.total_answers * 100);
			}
			else {
				for (int i=0; i<10+2+3+3+8; i++) {
					cout << " ";
				}
			}
			cout << endl;
		}

		void show_results() {
			for (int i=0; i<5; i++) {
				print_line(i);
			}	
		}

};


int main () {
	Pull my_pull = Pull();
	Answer a;
	a.animal = "Tanuki"; a.trait = "empatic"; a.item = "loli";
	my_pull.add_answers_to_pull(a);
	a.animal = "Kidsi"; a.trait = "hardworking"; a.item = "anime";
	my_pull.add_answers_to_pull(a);
	a.animal = "Tanuki"; a.trait = "empatic"; a.item = "sinkansen";
	my_pull.add_answers_to_pull(a);
	a.animal = "Tanuki"; a.trait = "social"; a.item = "nisan";
	my_pull.add_answers_to_pull(a);
	a.animal = "Kidsi"; a.trait = "lonely"; a.item = "sushi";
	my_pull.add_answers_to_pull(a);
	a.animal = "Dear"; a.trait = "hardworking"; a.item = "sushi";
	my_pull.add_answers_to_pull(a);
	a.animal = "Tanuki"; a.trait = "naturalistic"; a.item = "nuclear bomb";
	my_pull.add_answers_to_pull(a);

	for (int i=0; i< my_pull.trait.variants.size(); i++) {
		cout << my_pull.trait.variants[i] << " ";
	}
	my_pull.show_results();
	cout << endl;
	
	return 0;
}
