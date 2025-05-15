#include <iostream>
#include <string> // Include the string library
using namespace std;

int main() {
    // Initialize two strings
    string str1 = "Geeks";
    string str2 = "geeks";

    // Compare the strings
    if (str1 == str2) {
        cout << "str1 and str2 are equal" << endl;
    } else {
        cout << "str1 and str2 are not equal" << endl;
    }

    return 0;
}