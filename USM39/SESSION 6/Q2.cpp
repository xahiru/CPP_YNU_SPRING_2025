#include <iostream>
#include <string>
using namespace std;

string sliceString(const string& s) {
    return s.substr(1, s.length() - 2);
}

int main() {
    string s = "Hello";
    cout << sliceString(s) << endl; // Output: ell
    return 0;
}
