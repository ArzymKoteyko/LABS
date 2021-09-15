#include <iostream>
#include <string>

using namespace std;

int students_count;
int sum_mark;

string break_signal = "end"; 

// managing input from user
// if value was pased returns their aver
// if break_signal was pased returns -1
// plus gigving some feedback to user 
//
// TODO
// test
// make user output 
// coment
float manage_input() {
    string value;
    int mark;
    int sum = 0;
    float aver;
    cin >> value;
    if (value == break_signal) {
        return -1; // stops program
    }
    else {
        mark = stof(value); 
        for (int i=0; i<3; i++) {
            cin >> mark;
            sum += mark;
        }
        aver = sum / 4;
        return aver; // aver of 4 student marks
    }
}

int main () {
    int n;
    int counter = 0;
    float sum = 0;
    float total_aver;
    float input_res;
    cin >> n;
    // whisut break signal porcessing user input 
    // and 
    // updating total aver
    // TODO
    // make couter of bad students 
    for (int i=0; i<n; i++) {
        input_res = manage_input();
        if (input_res == -1) {
            cout << "END";
        }
        else {
            counter += 1;
            sum += input_res;
        }
    }
    total_aver = sum / counter;
    cout << total_aver;
    return 0;
}
