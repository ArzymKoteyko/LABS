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