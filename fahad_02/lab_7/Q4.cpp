#include <iostream>
#include <unordered_set>
#include <cctype>
using namespace std;

bool isPangram(const string &s) {
    unordered_set<char> letters;
    
    // Traverse through the string
    for (char ch : s) {
        // Convert to lowercase and check if the character is a letter
        if (isalpha(ch)) {
            letters.insert(tolower(ch)); // Insert the lowercase version of the character
        }
    }
    
    // Check if all 26 letters are present
    return letters.size() == 26;
}

int main() {
    string s;
    
    // Take input for the string
    cout << "Enter a string: ";
    getline(cin, s);
    
    // Check and output whether the string is a pangram or not
    if (isPangram(s)) {
        cout << "The string is a Pangram." << endl;
    } else {
        cout << "The string is not a Pangram." << endl;
    }

    return 0;
}
