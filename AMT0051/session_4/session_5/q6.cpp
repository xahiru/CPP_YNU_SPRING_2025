#include <iostream>
#include <vector>
#include <string>
#include <cctype>

bool containsNumber(const std::string& str) {
    for (char ch : str) {
        if (std::isdigit(ch)) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> filterStringsWithNumbers(const std::vector<std::string>& input) {
    std::vector<std::string> result;
    for (const std::string& s : input) {
        if (containsNumber(s)) {
            result.push_back(s);
        }
    }
    return result;
}

int main() {
    std::vector<std::string> original = {"red", "green23", "1black", "white"};


    std::vector<std::string> filtered = filterStringsWithNumbers(original);

    std::cout << "Strings that contain a number(s):\n";
    for (const std::string& s : filtered) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
