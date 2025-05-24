#include <iostream>
#include <string>
using namespace std;

int length_of_string(const string& s) {
    return s.length();
}

int main() {
    string s;
    cin >> s;

    cout << length_of_string(s) << endl;

    return 0;
}
