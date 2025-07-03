#include <iostream>
#include <string>
#include <unordered_map>

char findExtraCharacter(const std::string& s1, const std::string& s2) {
    std::unordered_map<char, int> charCount;

    for (char c : s1) {
        charCount[c]++;
    }

   
    for (char c : s2) {
        charCount[c]--;
        if (charCount[c] < 0) {
            return c; 
        }
    }

    return '\0'; 
}

int main() {
    std::string s1, s2;

    std::cout << "Enter string s1: ";
    std::getline(std::cin, s1);
    
    std::cout << "Enter string s2: ";
    std::getline(std::cin, s2);

    char extraChar = findExtraCharacter(s1, s2);
    if (extraChar) {
        std::cout << "Extra Character: " << extraChar << std::endl;
    } else {
        std::cout << "No extra character found." << std::endl;
    }

    return 0;
}