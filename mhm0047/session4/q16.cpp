#include <iostream>
#include <string>
using namespace std;

bool areStringsEqual(const string& a, const string& b) {
    return a == b;
}

int main() {
    string first = "Geeks";
    string second = "geeks";

    if (areStringsEqual(first, second)) {
        cout << "The strings are identical." << endl;
    } else {
        cout << "The strings are different." << endl;
    }

    return 0;
}
