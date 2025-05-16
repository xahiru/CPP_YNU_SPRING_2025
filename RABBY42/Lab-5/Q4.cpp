#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> capitalize(vector<string> vec) {
    for (auto& s : vec) {
        if (!s.empty()) s[0] = toupper(s[0]);
    }
    return vec;
}

int main() {
    vector<string> vec = {"red", "green", "black", "white", "Pink"};
    auto res = capitalize(vec);
    for (const auto& s : res) cout << s << " ";
    return 0;
}