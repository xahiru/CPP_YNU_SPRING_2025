#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool verifyLetters(const string& str1, const string& str2) {
    unordered_set<char> letters(str1.begin(), str1.end());
    for (char c : str2) {
        if (letters.find(c) == letters.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    string str1 = "hello";
    string str2 = "he";
    
    cout << (verifyLetters(str1, str2) ? "True" : "False") << endl;
    return 0;
}