#include <iostream>
#include <string>
using namespace std;

string sliceString(const string &s) {
    // Return the substring excluding the first and last characters
    return s.substr(1, s.length() - 2);
}

int main() {
    string s;

    // Input the string
    cout << "Enter a string: ";
    cin >> s;

    // Output the sliced string
    cout << "Output: " << sliceString(s) << endl;

    return 0;
}
