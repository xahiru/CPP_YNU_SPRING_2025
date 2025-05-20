#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

bool isPangram(const std::string& str) {
    std::unordered_set<char> letters;

    for (char c : str) {
        if (std::isalpha(c)) {
            letters.insert(std::tolower(c));
        }
    }

    return letters.size() == 26; // Check if we have all 26 letters
}

int main() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPangram(input)) {
        std::cout << "The string is a Pangram." << std::endl;
    } else {
        std::cout << "The string is not a Pangram." << std::endl;
    }

    return 0;
}