#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPangram(const string &s) {
    vector<bool> seen(26, false);
    for (char c : s) {
        if (isalpha(c)) {
            seen[tolower(c) - 'a'] = true;
        }
    }
    for (bool b : seen) {
        if (!b) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << (isPangram(s) ? "Pangram" : "Not a Pangram") << endl;

    return 0;
}