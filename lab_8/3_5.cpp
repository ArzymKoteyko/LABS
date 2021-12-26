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