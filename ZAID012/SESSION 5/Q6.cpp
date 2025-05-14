#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm> // Include this for std::any_of
using namespace std;

vector<string> filterStringsWithNumbers(const vector<string>& vec) {
    vector<string> result;
    for (const string& str : vec) {
        if (any_of(str.begin(), str.end(), ::isdigit)) {
            result.push_back(str);
        }
    }
    return result;
}

int main() {
    vector<string> vec = {"red", "green23", "1black", "white"};
    vector<string> filtered = filterStringsWithNumbers(vec);
    
    cout << "Strings containing numbers: ";
    for (const string& str : filtered) {
        cout << str << " ";
    }
    return 0;
}