#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";
    cout << s.substr(1, s.length() - 2) << endl;
    return 0;
}
