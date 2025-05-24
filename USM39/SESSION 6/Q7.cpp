#include <iostream>
#include <string>
using namespace std;

int findPattern(const string& s, const string& p) {
    size_t index = s.find(p);
    return (index != string::npos) ? index : -1;
}

int main() {
    string s = "Hello";
    string p = "llo";
    cout << findPattern(s, p) << endl; // Output: 2
    return 0;
}
