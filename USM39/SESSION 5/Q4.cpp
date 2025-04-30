#include <iostream>
#include <vector>
#include <cctype>

std::vector<std::string> capitalizeFirstLetter(std::vector<std::string> vec) {
    for (auto& str : vec) {
        if (!str.empty()) {
            str[0] = std::toupper(str[0]);
        }
    }
    return vec;
}

int main() {
    std::vector<std::string> vec = {"red", "green", "black", "white", "pink"};
    vec = capitalizeFirstLetter(vec);
    for (const auto& str : vec) {
        std::cout << str << " ";
    }
    return 0;
}
