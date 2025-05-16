#include <iostream>
#include <vector>
#include <string>
#include <cctype>

// Function to capitalize the first character of each string in the vector
std::vector<std::string> capitalizeFirstLetter(const std::vector<std::string>& input) {
    std::vector<std::string> result;

    for (const std::string& str : input) {
        if (!str.empty()) {
            std::string capitalized = str;  // Make a copy of the string
            capitalized[0] = std::toupper(capitalized[0]);  // Capitalize the first character
            result.push_back(capitalized);  // Add to result vector
        }
    }

    return result;
}

int main() {
    // Original vector
    std::vector<std::string> colors = {"red", "green", "black", "white", "pink"};

    // Capitalize first letter
    std::vector<std::string> capitalizedColors = capitalizeFirstLetter(colors);

    // Output results
    std::cout << "Original Vector elements:\n";
    for (const auto& color : colors) {
        std::cout << color << " ";
    }
    std::cout << "\nCapitalize the first character of each vector element:\n";
    for (const auto& color : capitalizedColors) {
        std::cout << color << " ";
    }
    std::cout << std::endl;

    return 0;
}