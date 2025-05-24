#include <iostream>
#include <string>
using namespace std;

string reverseString(const string& s) {
    return string(s.rbegin(), s.rend());
}

int main() {
    string s = "Hello";
    cout << reverseString(s) << endl; // Output: "olleH"
    return 0;
}
