#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";
    string result = s.substr(1, s.length() - 2);
    cout << result << endl;
    return 0;
}
