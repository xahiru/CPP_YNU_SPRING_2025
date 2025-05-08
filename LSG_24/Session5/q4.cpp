#include <iostream>
#include <unordered_set>
#include <cctype>
using namespace std;

bool containsAllLetters(const string& first, const string& second) {
    unordered_set<char> letters;
    for (char c : first) {
        letters.insert(tolower(c));
    }
    
    for (char c : second) {
        if (letters.find(tolower(c)) == letters.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    string first = "Hello World";
    string second = "old";
    
    cout << boolalpha << containsAllLetters(first, second);
    return 0;
}