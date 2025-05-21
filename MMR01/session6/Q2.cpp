#include <iostream>
#include <string>
using namespace std;

string sliceString(const string &s) {
    // Return substring from index 1 to length-2
    return s.substr(1, s.length() - 2);
}

int main() {
    // Test cases
    cout << sliceString("Hello") << endl;  
    cout << sliceString("World") << endl; 
    return 0;
}