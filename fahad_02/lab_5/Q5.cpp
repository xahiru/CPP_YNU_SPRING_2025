#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype> // For std::tolower

using namespace std;

// Function to check if all characters in 'target' exist in 'source' (case-insensitive)
bool containsAllCharacters(const string& source, const string& target) {
    unordered_map<char, int> sourceCount, targetCount;

    for (char ch : source) {
        sourceCount[tolower(ch)]++;
    }

    for (char ch : target) {
        targetCount[tolower(ch)]++;
    }

    for (const auto& entry : targetCount) {
        if (sourceCount[entry.first] < entry.second) {
            return false;
        }
    }

    return true;
}

// Helper to print a labeled result
void printResult(bool isValid) {
    cout << "\nResult: ";
    cout << (isValid ? "All letters are present." : "Some letters are missing.") << endl;
}

int main() {
    string text1, text2;

    cout << "Input base string: ";
    getline(cin, text1);

    cout << "Input string to verify against base: ";
    getline(cin, text2);

    bool check = containsAllCharacters(text1, text2);
    printResult(check);

    return 0;
}
