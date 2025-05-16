#include <iostream>
#include <vector>
#include <string>
#include <cctype> // for std::isdigit

// Function to check if a string contains a number
bool containsNumber(const std::string &str) {
    for (char ch : str) {
        if (std::isdigit(ch)) {
            return true; // If a digit is found, return true
        }
    }
    return false; // No digit found, return false
}

// Function to filter strings from a vector
std::vector<std::string> filterStringsContainingNumbers(const std::vector<std::string> &input) {
    std::vector<std::string> result;
    for (const std::string &str : input) {
        if (containsNumber(str)) {
            result.push_back(str); // Add strings that contain numbers to the result
        }
    }
    return result; // Return the filtered vector
}

int main() {
    // Original vector of strings
    std::vector<std::string> strings = {"red", "green23", "1black", "white"};

    // Filter the strings
    std::vector<std::string> filteredStrings = filterStringsContainingNumbers(strings);

    // Output the result
    std::cout << "Strings that contain numbers:\n";
    for (const std::string &str : filteredStrings) {
        std::cout << str << std::endl; // Print each filtered string
    }

    // If no strings were found, print a message
    if (filteredStrings.empty()) {
        std::cout << "No strings contain numbers." << std::endl;
    }

    return 0;
}