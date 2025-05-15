#include <iostream>
#include <vector>
#include <cctype>

std::vector<std::string> capitalizeFirstLetter(std::vector<std::string> words) {
    for (auto& word : words) {
        if (!word.empty()) {
            word[0] = toupper(word[0]);
        }
    }
    return words;
}

int main() {
    std::vector<std::string> words = {"red", "green", "black", "white", "Pink"};
    std::vector<std::string> result = capitalizeFirstLetter(words);
    
    std::cout << "Capitalize the first character of each vector element:\n";
    for (const auto& word : result) {
        std::cout << word << " ";
    }
    
    return 0;
}
