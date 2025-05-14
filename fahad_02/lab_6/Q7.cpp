#include <iostream>
#include <string>
using namespace std;

int findPattern(const string &s, const string &p) {
    size_t position = s.find(p);  // Find the first occurrence of pattern p in string s

    if (position != string::npos) {
        return static_cast<int>(position);  // Return the index if found
    }
    return -1;  // Return -1 if pattern is not found
}

int main() {
    string s, p;

    // Input the string and pattern
    cout << "Enter the main string: ";
    getline(cin, s);
    
    cout << "Enter the pattern to search for: ";
    getline(cin, p);

    // Output the result
    int result = findPattern(s, p);
    cout << "Pattern found at index: " << result << endl;

    return 0;
}
