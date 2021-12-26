#include <iostream>
#include <string> 
#include <vector>

using namespace std;

string input;
string reversed; 

vector<string> split (string data) {
    string buffer = "";
    vector<string> splited;
    for (int i=0; i<data.length(); i++) {
        if (data[i] == ' ') {
            splited.push_back(buffer);
            buffer = "";    
        }
        else {
            buffer.push_back(data[i]);
        }
    }
    splited.push_back(buffer);
    return splited;
}

void encode(vector<string> *data) {
    for (int i=0; i<data->size(); i++) {
        int n = (*data)[i].size();
        for (int j=0; j<n/2; j++) {
            char swap = (*data)[i][j];
            (*data)[i][j] = (*data)[i][n-j-1];
            (*data)[i][n-j-1] = swap;
        }
    }
}

int main () {
    cout << "Please enter string: ";
    getline(cin >> ws, input);
    vector<string> s = split(input);

    for (int i=0; i<s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl << endl;

    encode(&s);

    for (int i=0; i<s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl << endl;

    encode(&s);

    for (int i=0; i<s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    
    return 0;    
}