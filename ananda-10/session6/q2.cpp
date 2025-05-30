#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    if (s.length() > 2) {
    
        string sliced = s.substr(1, s.length() - 2);
        cout << "Sliced string: " << sliced << endl;
    } else {
        cout << "The string is too short to slice." << endl;
    }

    return 0;
}

