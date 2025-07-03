#include <iostream>
#include <algorithm>
using namespace std;

bool areAnagrams(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false; // Different lengths, cannot be anagrams
    }

    string sortedStr1 = str1;
    string sortedStr2 = str2;

    sort(sortedStr1.begin(), sortedStr1.end());
    sort(sortedStr2.begin(), sortedStr2.end());

    return sortedStr1 == sortedStr2; // Compare sorted strings
}

int main() {
    string str1 = "listen";
    string str2 = "silent";

    if (areAnagrams(str1, str2)) {
        cout << str1 << " and " << str2 << " are anagrams." << endl;
    } else {
        cout << str1 << " and " << str2 << " are not anagrams." << endl;
    }

    return 0;
}
