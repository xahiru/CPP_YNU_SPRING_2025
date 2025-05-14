#include <iostream>
#include <vector>
#include <string>
#include <cctype> // for isdigit

using namespace std;

// Function to check if a string contains at least one digit
bool containsDigit(const string& str) {
    for (char ch : str) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

// Function to filter strings with digits from a vector
vector<string> filterStringsWithNumbers(const vector<string>& inputVec) {
    vector<string> result;
    for (const string& word : inputVec) {
        if (containsDigit(word)) {
            result.push_back(word);
        }
    }
    return result;
}

// Helper function to print a vector of strings
void printVector(const vector<string>& vec, const string& title) {
    cout << title << "\n";
    for (const string& s : vec) {
        cout << s << " ";
    }
    cout << "\n\n";
}

int main() {
    vector<string> words = {"red", "green23", "1black", "white"};

    printVector(words, "Original Vector elements:");

    vector<string> filtered = filterStringsWithNumbers(words);

    printVector(filtered, "Find strings that contain a number(s) from the said vector:");

    return 0;
}
