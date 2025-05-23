#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int L, R;

    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter L (start index): ";
    cin >> L;
    cout << "Enter R (end index): ";
    cin >> R;

    if (L >= 0 && R < s.length() && L <= R) {
    
        string sub = s.substr(L, R - L + 1);
        cout << "Substring: " << sub << endl;
    } else {
        cout << "Invalid indices!" << endl;
    }

    return 0;
}

