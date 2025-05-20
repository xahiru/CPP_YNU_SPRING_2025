#include <iostream>
#include <string>

void findPatternOccurrences(const std::string& text, const std::string& pattern) {
    size_t textLength = text.length();
    size_t patternLength = pattern.length();

    for (size_t i = 0; i <= textLength - patternLength; ++i) {
        if (text.substr(i, patternLength) == pattern) {
            std::cout << "Pattern found at " << i << std::endl;
        }
    }
}

int main() {
    std::string text, pattern;

    std::cout << "Enter the text: ";
    std::getline(std::cin, text);
    
    std::cout << "Enter the pattern: ";
    std::getline(std::cin, pattern);

    findPatternOccurrences(text, pattern);

    return 0;
}