#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length()) {

        return false;
    }

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
    
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (areAnagrams(s1, s2) ? "Anagrams" : "Not Anagrams") << endl;


    return 0;
}