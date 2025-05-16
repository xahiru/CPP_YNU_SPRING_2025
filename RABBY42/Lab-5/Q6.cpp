#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> filter(const vector<string>& vec) {
    vector<string> res;
    for (const auto& s : vec) {
        for (char c : s) {
            if (isdigit(c)) {
                res.push_back(s);
                break;
            }
        }
    }
    return res;
}

int main() {
    vector<string> vec = {"red", "green23", "1black", "white"};
    auto res = filter(vec);
    for (const auto& s : res) cout << s << " ";
    return 0;
}