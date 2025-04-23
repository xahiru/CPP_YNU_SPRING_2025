#include <iostream>
using namespace std;

int main() {
    const char* str = "A string.";  
    const char* ptr = str;          

    cout << str[0] << " " << static_cast<const void*>(ptr) << " " << str[3] << endl;

    ptr = ptr + 2;

    cout << static_cast<const void*>(ptr) << " " << ptr[2] << " " << ptr[4] << endl;

    return 0;
}

