#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPangram(const string& s) {
    bool seen[26] = {false};
    for (char c : s) {
        if (isalpha(c)) {
            seen[tolower(c) - 'a'] = true;
        }
    }
    for (bool b : seen) {
        if (!b) return false;
    }
    return true;
}

int main() {
    string s = "The quick brown fox jumps over the lazy dog";
    cout << (isPangram(s) ? "Pangram" : "Not a Pangram") << endl;
    return 0;
}