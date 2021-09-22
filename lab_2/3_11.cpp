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
float manage_input() {
    string value;
    bool fail_flag = false;
    int mark;
    int sum = 0;
    float aver;
    for (int i=0; i<4; i++) {
        // add student mark to aver sum
        cin >> value;
        if (value == break_signal) {
            return -1;
        }
        mark = stof(value);
        if (mark == 2) {
            fail_flag = true;
        }
        sum += mark;
    }
    aver = sum / 4;
    if (fail_flag) {
        cout << "Student marks wont count\n\n";
        return -2;
    }
    else {
        cout << "\n";
        return aver; // aver of 4 student marks
    }
}

int main () {
    int counter = 0;
    int bad_counter = 0;
    float sum = 0;
    float total_aver;
    float input_res;
    cout << "To finish programm enter <end>\n";
    while (true) {
        cout << "Enter student marks: ";
        input_res = manage_input();
        if (input_res == -1) {
            cout << "End of a programm\n";
            break;
        }
        else if (input_res == -2) {
            bad_counter += 1;
        }
        else {
            counter += 1;
            sum += input_res;
        }
    }
    total_aver = sum / counter;
    cout << "\n";
    cout << "Average students mark: " << total_aver << "\n";
    cout << "Bad students: " << bad_counter << "\n";
    return 0;
}
