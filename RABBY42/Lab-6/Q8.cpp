#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int L, R;
    cin >> s >> L >> R;
    cout << s.substr(L, R - L + 1);
    return 0;
}