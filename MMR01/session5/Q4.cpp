#include <iostream>
#include <vector>
#include <string>
#include <cctype> // For std::toupper
using namespace std;

// Function to capitalize the first letter of each string in the vector
vector<string> capitalizeFirstLetter(const vector<string>& vec) {
    vector<string> capitalizedVec; // Vector to store the capitalized strings

    for (const string& str : vec) {
        if (!str.empty()) { // Check if the string is not empty
            string capitalizedStr = str; // Create a copy of the string
            capitalizedStr[0] = toupper(capitalizedStr[0]); // Capitalize the first character
            capitalizedVec.push_back(capitalizedStr); // Add to the result vector
        } else {
            capitalizedVec.push_back(str); // If empty, just add it
        }
    }

    return capitalizedVec; // Return the modified vector
}

int main() {
    // Original vector elements
    vector<string> colors = {"red", "green", "black", "white", "pink"};

    cout << "Original Vector elements: ";
    for (const string& color : colors) {
        cout << color << " ";
    }
    cout << endl;

    // Capitalize the first letter of each vector element
    vector<string> capitalizedColors = capitalizeFirstLetter(colors);

    // Output the result
    cout << "Capitalize the first character of each vector element: ";
    for (const string& color : capitalizedColors) {
        cout << color << " ";
    }
    cout << endl;

    return 0;
}