#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool verifyLetters(const string& first, const string& second) {
    unordered_set<char> firstLetters;
    
    // Store all unique letters from the first string
    for (char c : first) {
        if (isalpha(c)) {
            firstLetters.insert(tolower(c));
        }
    }
    
    // Check each letter in the second string
    for (char c : second) {
        if (isalpha(c)) {
            if (firstLetters.find(tolower(c)) == firstLetters.end()) {
                return false;
            }
       
        }
    }
    
   
    return true;
}

int main() {
    
    string first, second;
    
    cout << "Enter the first string: ";
    getline(cin, first);
    
    cout << "Enter the second string: ";
    getline(cin, second);
    
    bool result = verifyLetters(first, second);
    
    cout << "Do all letters of the second string appear in the first? "
         << (result ? "Yes" : "No") << endl;
    
    return 0;

}