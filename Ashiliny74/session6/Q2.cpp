#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Input: ";
    cin >> s;

    // Slicing the string
    string sliced = s.substr(1, s.length() - 2);
    cout << "Output: " << sliced << endl;

    return 0;
}