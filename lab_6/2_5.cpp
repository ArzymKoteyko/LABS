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
