#include <iostream>
#include <string>
#include <bitset>
#include <cctype>
using namespace std;

bool isPangram(const string &s) {
    bitset<26> letters;
    for (char c : s) {
        if (isalpha(c)) {
            letters.set(tolower(c) - 'a');
        }
    }
    return letters.all();
}

int main() {
    string s;
    getline(cin, s);
    cout << (isPangram(s) ? "Pangram" : "Not a Pangram") << endl;
    return 0;
}