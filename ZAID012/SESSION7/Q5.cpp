#include <iostream>
#include <string>
#include <unordered_map>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    std::unordered_map<char, int> charCount;

    
    for (char c : str1) {
        charCount[c]++;
    }

    
    for (char c : str2) {
        charCount[c]--;
        if (charCount[c] < 0) {
            return false; 
        }
    }

    return true; 
}

int main() {
    std::string str1, str2;

    std::cout << "Enter first string: ";
    std::getline(std::cin, str1);
    
    std::cout << "Enter second string: ";
    std::getline(std::cin, str2);

    if (areAnagrams(str1, str2)) {
        std::cout << "The strings are anagrams." << std::endl;
    } else {
        std::cout << "The strings are not anagrams." << std::endl;
    }

    return 0;
}