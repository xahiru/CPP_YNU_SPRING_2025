#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, p;
    getline(cin, s);
    getline(cin, p);
    size_t pos = s.find(p);
    if (pos != string::npos) {
        cout << pos;
    } else {
        cout << -1;
    }
    return 0;
}