#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> capitalizeFirst(vector<string> strs) {
    for (auto& s : strs) {
        if (!s.empty()) {
            s[0] = toupper(s[0]);
        }
    }
    return strs;
}

int main() {
    vector<string> colors = {"red", "green", "black", "white", "Pink"};
    vector<string> result = capitalizeFirst(colors);
    
    cout << "Capitalize the first character of each vector element:\n";
    for (const auto& s : result) {
        cout << s << " ";
    }
    return 0;
}