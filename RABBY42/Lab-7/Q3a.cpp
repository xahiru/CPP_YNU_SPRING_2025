#include <iostream>
using namespace std;

char findExtra(string s1, string s2) {
    int sum = 0;
    for (char c : s2) sum += c;
    for (char c : s1) sum -= c;
    return sum;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "Extra Character: " << findExtra(s1, s2);
    return 0;
}
