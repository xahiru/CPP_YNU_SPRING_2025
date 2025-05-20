#include <iostream>
#include <cctype>
using namespace std;

bool isPangram(string s) {
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
    cout << (isPangram("The quick brown fox jumps over the lazy dog") ? "Pangram" : "Not a pangram");
    return 0;
}