#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

bool isPangram(const std::string& str) {
    std::unordered_set<char> letters;

    for (char ch : str) {
        if (std::isalpha(ch)) {
            letters.insert(std::tolower(ch));
        }
    }

    return letters.size() == 26;
}

int main() {
    std::string input1 = "The quick brown fox jumps over the lazy dog";
    std::string input2 = "Hello World";

    std::cout << "Input 1: " << (isPangram(input1) ? "Pangram" : "Not a Pangram") << std::endl;
    std::cout << "Input 2: " << (isPangram(input2) ? "Pangram" : "Not a Pangram") << std::endl;

    return 0;
}
