#include <iostream>
#include <string>
#include <unordered_set> // For using unordered_set
using namespace std;

// Function to verify if all letters in the second string appear in the first string
bool verifyLetters(const string& str1, const string& str2) {
    unordered_set<char> charSet; // Set to store characters of the first string

    // Insert all characters of the first string into the set
    for (char ch : str1) {
        charSet.insert(ch);
    }

    // Check if each character in the second string is in the set
    for (char ch : str2) {
        if (charSet.find(ch) == charSet.end()) {
            return false; // If any character is not found, return false
        }
    }

    return true; // All characters found, return true
}

int main() {
    // Input strings
    string str1, str2;

    cout << "Enter the first string: ";
    getline(cin, str1); // Read the first string

    cout << "Enter the second string: ";
    getline(cin, str2); // Read the second string

    // Verify letters
    bool result = verifyLetters(str1, str2);

    // Output the result
    if (result) {
        cout << "All letters in the second string appear in the first string." << endl;
    } else {
        cout << "Not all letters in the second string appear in the first string." << endl;
    }

    return 0;
}