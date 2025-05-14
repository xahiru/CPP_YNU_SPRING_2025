#include <iostream>
#include <algorithm> // for reverse function
using namespace std;

string reverseString(const string &s) {
    string reversed = s; // Create a copy of the original string
    reverse(reversed.begin(), reversed.end()); // Reverse the string using reverse function
    return reversed;
}

int main() {
    string s;

    // Input the string
    cout << "Enter a string: ";
    cin >> s;

    // Output the reversed string
    cout << "Reversed string: " << reverseString(s) << endl;

    return 0;
}
