#include <iostream>
#include <algorithm>
using namespace std;

void permute(string s, int l = 0) {                     // Function with default left index
    if (l == s.length()-1) cout << s << endl;           // Base case: print when at last character
    else for (int i = l; i < s.length(); i++) {         // Loop through remaining characters
        swap(s[l], s[i]);                               // Swap current with first position
        permute(s, l+1);                                // Recurse on remaining substring
    }                                                   // (swap back happens automatically)
}

int main() {
    string s; cout << "Input a string: "; cin >> s;      // Ask user input string
    cout << "All permutations of the string:\n";         // Print header
    permute(s);                                          // Start permutation
}