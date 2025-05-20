#include <iostream>
using namespace std;

int main() {
    const char* str = "A string.";
    const char* ptr = str;

    cout << *ptr << " " << static_cast<const void*>(ptr) << " " << str[3] << endl;

    ptr = ptr + 2;

    cout << static_cast<const void*>(ptr) << " " << ptr[1] << " " << ptr[2] << endl;

    return 0;
}
