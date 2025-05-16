#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "cdbkdub";
    int L = 0, R = 5;
    cout << s.substr(L, R - L + 1) << endl;
    return 0;
}
