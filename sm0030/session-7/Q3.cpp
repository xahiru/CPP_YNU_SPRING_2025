#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    unordered_map<char, int> count;

    for (char c : s2) count[c]++;
    for (char c : s1) count[c]--;

    for (auto pair : count) {
        if (pair.second != 0) {
            cout << "Extra Character: " << pair.first << endl;
            break;
        }
    }

    return 0;
}
