#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str, rev;
    cout << "Enter a string: ";
    cin >> str;

    rev = str;
    reverse(rev.begin(), rev.end());

    if (str == rev)
        cout << "Palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;

    return 0;
}
