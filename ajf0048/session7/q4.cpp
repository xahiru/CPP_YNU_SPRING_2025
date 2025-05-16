#include <iostream>
#include <cctype>
using namespace std;

bool isPangram(const string& str) {
    bool alphabet[26] = {false}; // Track occurrences of each letter

    for (char c : str) {
        if (isalpha(c)) {
            alphabet[tolower(c) - 'a'] = true; // Mark the letter as found
        }
    }

    for (bool found : alphabet) {
        if (!found) {
            return false; // Missing at least one letter
        }
    }
    return true; // Contains all letters
}

int main() {
    string str = "The quick brown fox jumps over the lazy dog";
    if (isPangram(str)) {
        cout << "The string is a pangram." << endl;
    } else {
        cout << "The string is not a pangram." << endl;
    }

    return 0;
}
