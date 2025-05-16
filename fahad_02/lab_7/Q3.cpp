#include <iostream>
#include <string>
using namespace std;

char findExtraCharacter(const string &s1, const string &s2) {
    char extraChar = 0; // Initialize with 0
    
    // XOR all characters of both strings
    for (int i = 0; i < s1.length(); i++) {
        extraChar ^= s1[i];
    }
    for (int i = 0; i < s2.length(); i++) {
        extraChar ^= s2[i];
    }
    
    return extraChar; // This will be the extra character
}

int main() {
    string s1, s2;
    
    // Take input for strings s1 and s2
    cout << "Enter the first string (s1): ";
    cin >> s1;
    cout << "Enter the second string (s2): ";
    cin >> s2;
    
    // Find and output the extra character
    char extraCharacter = findExtraCharacter(s1, s2);
    cout << "Extra Character: " << extraCharacter << endl;

    return 0;
}
