// LEVEL 3 
// TASK 2

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

//-------------------------------------------//
// LEVL 3
// TASK 5 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string data = "Sed ut perspiciatis, unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, explicabo. Nemo enim ipsam voluptatem, quia voluptas sit, aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos, qui ratione voluptatem sequi nesciunt, neque porro quisquam est, qui dolorem ipsum, quia dolor sit, amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt, ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit, qui in ea voluptate velit esse, quam nihil molestiae consequatur, vel illum, qui dolorem eum fugiat, quo voluptas nulla pariatur? At vero eos et accusamus et iusto odio dignissimos ducimus, qui blanditiis praesentium voluptatum deleniti atque corrupti, quos dolores et quas molestias excepturi sint, obcaecati cupiditate non provident, similique sunt in culpa, qui officia deserunt mollitia animi, id est laborum et dolorum fuga. Et harum quidem rerum facilis est et expedita distinctio. Nam libero tempore, cum soluta nobis est eligendi optio, cumque nihil impedit, quo minus id, quod maxime placeat, facere possimus, omnis voluptas assumenda est, omnis dolor repellendus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet, ut et voluptates repudiandae sint et molestiae non recusandae. Itaque earum rerum hic tenetur a sapiente delectus, ut aut reiciendis voluptatibus maiores alias consequatur aut perferendis doloribus asperiores repellat.";

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


char lover(char letter) {
    if (letter < 97) {
        letter += 32;
    } 
    return letter;
}


int main () {

    vector<string> s;
    s = split(data);
    int alphabet[26];

    for (int i=0; i<26; i++) {
        alphabet[i] = 0;        
    }
    for (int i=0; i<s.size(); i++) {
        alphabet[lover(s[i][0]) - 97]++;
    }
    for (int i=0; i<26; i++) {
        cout << char(i+97) << " : " << alphabet[i] << endl;
    }
    cout << endl;
    return 0;
}

//-------------------------------------------//
// LEVL 3
// TASK 6 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string input = "Sed ut perspiciatis, unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, explicabo. Nemo enim ipsam voluptatem, quia voluptas sit, aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos, qui ratione voluptatem sequi nesciunt, neque porro quisquam est, qui dolorem ipsum, quia dolor sit, amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt, ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit, qui in ea voluptate velit esse, quam nihil molestiae consequatur, vel illum, qui dolorem eum fugiat, quo voluptas nulla pariatur? At vero eos et accusamus et iusto odio dignissimos ducimus, qui blanditiis praesentium voluptatum deleniti atque corrupti, quos dolores et quas molestias excepturi sint, obcaecati cupiditate non provident, similique sunt in culpa, qui officia deserunt mollitia animi, id est laborum et dolorum fuga. Et harum quidem rerum facilis est et expedita distinctio. Nam libero tempore, cum soluta nobis est eligendi optio, cumque nihil impedit, quo minus id, quod maxime placeat, facere possimus, omnis voluptas assumenda est, omnis dolor repellendus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet, ut et voluptates repudiandae sint et molestiae non recusandae. Itaque earum rerum hic tenetur a sapiente delectus, ut aut reiciendis voluptatibus maiores alias consequatur aut perferendis doloribus asperiores repellat.";

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

int main()
{
    int syllables_in_words[10];
    char volvels[] = {'a', 'e', 'i', 'o', 'u', 'y'};

    for (int i=0; i<10; i++) {
        syllables_in_words[i] = 0;
    }


    vector<string> word_array;

    word_array = split(input);
    for (int i=0; i<word_array.size(); i++) {
        if (word_array[i].length() == 1) {
            syllables_in_words[0]++;
            cout << endl;
            continue;
        }
        int total = 0;
        for (int j=0; j<word_array[i].length(); j++) {
            for (int v=0; v<6; v++) {
                if (word_array[i][j] == volvels[v]) {
                    total++;
                    break;
                }
            }
        }
        syllables_in_words[total-1]++;

    }

    for (int i=0; i<10; i++) {
        cout << i+1 << " : " <<syllables_in_words[i] << endl;
    }
    cout << endl;
    return 0;
}