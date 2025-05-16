#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

bool containsDigit(const string& str) {
    for (char ch : str) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

vector<string> extractStringsWithDigits(const vector<string>& input) {
    vector<string> filtered;
    for (const auto& item : input) {
        if (containsDigit(item)) {
            filtered.push_back(item);
        }
    }
    return filtered;
}

int main() {
    vector<string> words = {"red", "green23", "1black", "white"};
    vector<string> result = extractStringsWithDigits(words);

    cout << "Find strings that contain a number(s) from the said vector:\n";
    for (const auto& word : result) {
        cout << word << " ";
    }

    return 0;
}
