#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>

bool isPangram(const std::string& str) {
    std::unordered_set<char> letters;
    for (char c : str) {
        if (std::isalpha(c)) {
            letters.insert(std::tolower(c));
        }
    }
    return letters.size() == 26;
}

int main() {
    std::string input = "The quick brown fox jumps over the lazy dog";
    if (isPangram(input)) {
        std::cout << "It is a Pangram" << std::endl;
    } else {
        std::cout << "Not a Pangram" << std::endl;
    }
    return 0;
}
