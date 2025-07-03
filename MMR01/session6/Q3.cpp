#include <iostream>
#include <string>
using namespace std;

int stringLength(const string &s) {
    return s.length();  // Returns the number of characters in the string
}

int main() {
    // Test cases
    cout << stringLength("Yunnan") << endl;   
    cout << stringLength("Hello1234") << endl; 
    return 0;
}