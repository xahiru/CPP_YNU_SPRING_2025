#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> filterStringsWithNumbers(const std::vector<std::string>& vec) {
    std::vector<std::string> result;
    for (const auto& str : vec) {
        for (char ch : str) {
            if (std::isdigit(ch)) {
                result.push_back(str);
                break;
            }
        }
    }
    return result;
}

int main() {
    std::vector<std::string> vec = {"red", "green23", "1black", "white"};
    auto result = filterStringsWithNumbers(vec);
    for (const auto& str : result) {
        std::cout << str << " ";
    }
    return 0;
}
