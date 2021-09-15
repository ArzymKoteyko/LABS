#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Ring params
float radius_1, radius_2;
// Point ammount
int n;
// Break signals
string break_signal = "end";
string value;

// Couters
int total_inside = 0;
int total_outside = 0;

// Point cords
float px, py;

// Checks if point (x, y) stays in ring with given radius
bool in_ring(float x, float y) {
    float dist = pow(pow(x, 2) + pow(y, 2), 0.5);
    if (dist >= radius_1 && dist <= radius_2) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    // Console Log
    // and
    // Value initialization
    cout << "Please nter ammount of dots: ";
    cin >> n;
    cout << "Enter inside radius: ";
    cin >> radius_1;
    cout << "Enter outside radius: ";
    cin >> radius_2;
    cout << "To stop program enter <end>\n";
    // Main cycle
    for (int i =0; i < n; i++) {
        cout << "Enter point cords: ";
        cin >> value;
        // Checking break condition
        if (value == break_signal) {
            cout << "end\n";
            break;
        }
        else {
            // First cord input
            px = stof(value);
        }
        // Second cord input
        cin >> py;
        // Checking where is point
        // and
        // Updating cunters
        if (in_ring(px, py)) {
            cout << "Point is inside\n";
            total_inside += 1;
        }
        else {
            cout << "Point is outside\n";
            total_outside += 1;
        }
    }
    // Final Console log
    cout << "Total point ammount: " << total_inside + total_outside << "\n";
    cout << "Inside: " << total_inside << "\n";
    cout << "Outside: " << total_outside << "\n";
    return 0;
}

