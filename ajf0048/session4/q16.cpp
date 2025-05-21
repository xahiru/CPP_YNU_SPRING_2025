#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char* str1 = "Geeks";
    const char* str2 = "geeks";

    if (strcmp(str1, str2) == 0) {
        cout << "str1 and str2 are equal." << endl;
    } else {
        cout << "str1 and str2 are not equal." << endl;
    }

    return 0;
}
