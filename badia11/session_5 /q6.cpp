 #include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> filterStringsWithNumbers(const std::vector<std::string>& words) {
    std::vector<std::string> result;
    
    for (const auto& word : words) {
        for (char c : word) {
            if (isdigit(c)) {
                result.push_back(word);
                break;
            }
        }
    }
    
