#include <iostream>
#include <string>

using namespace std;

void compareStrings(const string& str1, const string& str2) {
    if (str1 == str2) {
        cout << "str1 and str2 are equal." << endl;
    } else {
        cout << "str1 and str2 are not equal." << endl;
    }
}

int main() {
    string str1, str2;
    
    cout << "Enter first string: ";
    getline(cin, str1);
    
    cout << "Enter second string: ";
    getline(cin, str2);
    
    compareStrings(str1, str2);
    
    return 0;
}