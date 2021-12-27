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