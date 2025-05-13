#include <iostream>
#include <unordered_set>
using namespace std;

bool verifyLetters(const string& first, const string& second) {
    unordered_set<char> chars;
    for (char c : first) {
        chars.insert(tolower(c));
    }
    
    for (char c : second) {
        if (chars.find(tolower(c)) == chars.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    string first = "Programming";
    string second = "gram";
    
    cout << (verifyLetters(first, second) ? "true" : "false") << endl;
    return 0;
}