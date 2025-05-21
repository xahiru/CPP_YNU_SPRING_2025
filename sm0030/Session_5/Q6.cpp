#include <iostream>
#include <vector>
#include <string>
#include <cctype>

bool containsNumber(const std::string& s) {
    for (char c : s) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> filterStringsWithNumbers(const std::vector<std::string>& vec) {
    std::vector<std::string> result;
    for (const std::string& s : vec) {
        if (containsNumber(s)) {
            result.push_back(s);
        }
    }
    return result;
}

int main() {
    std::vector<std::string> originalVector = {"red", "green23", "1black", "white"};
    std::cout << "Original Vector elements:";
    for (const std::string& s : originalVector) {
        std::cout << " " << s;
    }
    std::cout << std::endl;

    std::vector<std::string> filteredVector = filterStringsWithNumbers(originalVector);
    std::cout << "Find strings that contain a number(s) from the said vector:";
    for (const std::string& s : filteredVector) {
        std::cout << " " << s;
    }
    std::cout << std::endl;

    std::vector<std::string> noNumbersVector = {"apple", "banana", "cherry"};
    std::cout << "Original Vector elements:";
    for (const std::string& s : noNumbersVector) {
        std::cout << " " << s;
    }
    std::cout << std::endl;
    filteredVector = filterStringsWithNumbers(noNumbersVector);
    std::cout << "Find strings that contain a number(s) from the said vector:";
    if (filteredVector.empty()) {
        std::cout << " (empty vector)";
    }
    for (const std::string& s : filteredVector) {
        std::cout << " " << s;
    }
    std::cout << std::endl;

    return 0;
}