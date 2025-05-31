#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int length = s.length();
    cout << "Length: " << length << endl;

    return 0;
}

