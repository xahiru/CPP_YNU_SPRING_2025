#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> filterStringsWithNumbers(const vector<string>& v) {
    vector<string> result;
    for (const auto& s : v) {
        for (char c : s) {
            if (isdigit(c)) {
                result.push_back(s);
                break;
            }
        }
    }
    return result;
}

int main() {
    vector<string> v = {"red", "green23", "1black", "white"};
    vector<string> result = filterStringsWithNumbers(v);
    
    cout << "Find strings that contain a number(s) from the said vector:\n";
    for (const auto& s : result) {
        cout << s << " ";
    }
    return 0;
}