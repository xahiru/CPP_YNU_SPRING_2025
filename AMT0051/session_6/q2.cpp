#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "World";
    
    if (s.length() > 2) {
        string result = s.substr(1, s.length() - 2);
        cout << result << endl;
    } else {
        cout << "String is too short!" << endl;
    }

    return 0;
}
