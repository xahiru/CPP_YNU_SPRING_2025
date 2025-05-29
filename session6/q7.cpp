#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, p;

    cout << "Enter the main string (s): ";
    getline(cin, s);

    cout << "Enter the pattern (p): ";
    getline(cin, p);

    size_t index = s.find(p); 

    if (index != string::npos) {
        cout << "Pattern found at index: " << index << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}

