#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

bool areAnagrams(string s1, string s2) {
    
    if (s1.length() != s2.length()) {
        return false;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    getline(cin, str1);

    cout << "Enter second string: ";
    getline(cin, str2);

    if (areAnagrams(str1, str2)) {
        cout << "Strings are anagrams." << endl;
    } else {
        cout << "Strings are not anagrams." << endl;
    }

    return 0;
}

