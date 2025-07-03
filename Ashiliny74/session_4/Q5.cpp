#include <iostream>
#include <string>
#include <unordered_map>

bool verifyLetters(const std::string &first, const std::string &second) {
    std::unordered_map<char, int> charCount;

    // Count characters in the first string
    for (char c : first) {
        if (isalpha(c)) {  // Check if the character is a letter
            charCount[c]++;
        }
    }

    // Verify characters in the second string
    for (char c : second) {
        if (isalpha(c)) {  // Check if the character is a letter
            if (charCount[c] == 0) {
                return false;  // Character not found in first string
            }
        }
    }

    return true;  // All characters in second string found in first string
}

int main() {
    std::string firstString;
    std::string secondString;

    // Input first string
    std::cout << "Enter the first string: ";
    std::getline(std::cin, firstString);

    // Input second string
    std::cout << "Enter the second string: ";
    std::getline(std::cin, secondString);

    // Verify letters
    if (verifyLetters(firstString, secondString)) {
        std::cout << "All letters of the second string are present in the first string." << std::endl;
    } else {
        std::cout << "Not all letters of the second string are present in the first string." << std::endl;
    }

    return 0;
}