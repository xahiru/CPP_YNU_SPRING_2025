#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPangram(const string &s) {
    bool letters[26] = {false};
    for (char c : s) {
        if (isalpha(c)) {
            letters[tolower(c) - 'a'] = true;
        }
    }
    for (bool present : letters) {
        if (!present) return false;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << (isPangram(s) ? "Pangram" : "Not a Pangram") << endl;
    return 0;
}