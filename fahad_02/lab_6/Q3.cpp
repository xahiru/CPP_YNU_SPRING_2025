#include <iostream>
#include <string>
using namespace std;

int getStringLength(const string &s) {
    return s.length(); // Return the length of the string
}

int main() {
    string s;

    // Input the string
    cout << "Enter a string: ";
    cin >> s;

    // Output the length of the string
    cout << "Length of the string: " << getStringLength(s) << endl;

    return 0;
}
