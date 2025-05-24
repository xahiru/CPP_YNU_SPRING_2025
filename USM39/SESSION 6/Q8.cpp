#include <iostream>
#include <string>
using namespace std;

void printSubstring(const string& s, int L, int R) {
    cout << s.substr(L, R - L + 1) << endl;
}

int main() {
    string s = "cdbkdub";
    printSubstring(s, 0, 5); // Output: "cdbkdu"
    return 0;
}
