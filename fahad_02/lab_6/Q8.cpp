#include <iostream>
#include <string>
using namespace std;

string getSubstring(const string &s, int L, int R) {
    // The substr function takes the starting index and length as arguments
    return s.substr(L, R - L + 1);
}

int main() {
    string s;
    int L, R;

    // Input the string and the indices L and R
    cout << "Enter the string: ";
    getline(cin, s);
    
    cout << "Enter the left index L: ";
    cin >> L;
    
    cout << "Enter the right index R: ";
    cin >> R;

    // Output the substring
    cout << "The substring from index " << L << " to " << R << " is: " << getSubstring(s, L, R) << endl;

    return 0;
}
