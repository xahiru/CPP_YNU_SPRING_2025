#include <iostream>
#include <string>
using namespace std;

int findPattern(const string &s, const string &p) {
    size_t found = s.find(p);
    if (found != string::npos) {
        return found;
    }
    return -1;
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << findPattern(s, p) << endl;
    return 0;
}