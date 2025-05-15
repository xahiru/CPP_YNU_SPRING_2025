#include <iostream>
#include <algorithm>
using namespace std;

bool areAnagrams(const string &str1, const string &str2) {
    // If lengths are different, they cannot be anagrams
    if (str1.length() != str2.length()) {
        return false;
    }
    
    // Sort both strings
    string sorted_str1 = str1;
    string sorted_str2 = str2;
    
    sort(sorted_str1.begin(), sorted_str1.end());
    sort(sorted_str2.begin(), sorted_str2.end());
    
    // If the sorted strings are equal, then they are anagrams
    return sorted_str1 == sorted_str2;
}

int main() {
    string str1, str2;
    
    // Take input for two strings
    cout << "Enter first string: ";
    getline(cin, str1);
    
    cout << "Enter second string: ";
    getline(cin, str2);
    
    // Check and output whether the strings are anagrams or not
    if (areAnagrams(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
