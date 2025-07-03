#include <iostream>
#include <cctype>
using namespace std;

bool isPangram(string s) {
    bool letters[26] = {false};
    for (char c : s) {
        if (isalpha(c)) letters[tolower(c) - 'a'] = true;
    }
    for (bool b : letters) if (!b) return false;
    return true;
}


int main() {
    string s;
    getline(cin, s);
    cout << (isPangram(s) ? "Pangram" : "Not a pangram");
    return 0;
}
