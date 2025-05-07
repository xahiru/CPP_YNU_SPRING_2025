#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

vector<string> filterWithNumbers(const vector<string>& strs) {
    vector<string> result;
    for (const auto& s : strs) {
        if (any_of(s.begin(), s.end(), ::isdigit)) {
            result.push_back(s);
        }
    }
    return result;
}

int main() {
    vector<string> words = {"red", "green23", "1black", "white"};
    vector<string> result = filterWithNumbers(words);
    
    cout << "Find strings that contain a number(s) from the said vector:\n";
    for (const auto& s : result) {
        cout << s << " ";
    }
    return 0;
}