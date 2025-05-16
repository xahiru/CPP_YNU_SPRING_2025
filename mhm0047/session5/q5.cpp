#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

bool areAllLettersPresent(const string& source, const string& target) {
    set<char> sourceLetters;
    
    for (char ch : source) {
        sourceLetters.insert(tolower(ch));
    }

    for (char ch : target) {
        if (sourceLetters.count(tolower(ch)) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string source = "Programming";
    string target = "gram";

    cout << (areAllLettersPresent(source, target) ? "true" : "false") << endl;
    return 0;
}
