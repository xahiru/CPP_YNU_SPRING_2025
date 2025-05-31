#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool allLettersExist(const string& str1, const string& str2) {
    for (char ch : str2) {
        if (str1.find(ch) == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    bool result = allLettersExist(str1, str2);

    cout << "Do all letters of the second string appear in the first string? ";
    cout << (result ? "True" : "False") << endl;

    return 0;
}
