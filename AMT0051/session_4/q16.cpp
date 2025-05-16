#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Geeks";
    string str2 = "geeks";

    if (str1 == str2) {
        cout << "str1 and str2 are equal" << endl;
    } else {
        cout << "str1 and str2 are not equal" << endl;
    }

    return 0;
}
