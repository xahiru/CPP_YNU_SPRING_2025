#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool areAnagrams(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (areAnagrams(s1, s2))
        cout << "Anagrams" << endl;
    else
        cout << "Not Anagrams" << endl;

    return 0;
}
