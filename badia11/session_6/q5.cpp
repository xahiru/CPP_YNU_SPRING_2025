#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s = "Hello";
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
