#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> capitalizeFirstLetter(vector<string> v) {
    for (auto& s : v) {
        if (!s.empty()) {
            s[0] = toupper(s[0]);
        }
    }
    return v;
}

int main() {
    vector<string> v = {"red", "green", "black", "white", "Pink"};
    vector<string> result = capitalizeFirstLetter(v);
    
    cout << "Capitalize the first character of each vector element:\n";
    for (const auto& s : result) {
        cout << s << " ";
    }
    return 0;
}
