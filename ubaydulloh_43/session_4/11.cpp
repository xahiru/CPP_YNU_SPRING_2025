#include <iostream>
using namespace std;

int main() {
    const char* str = "A string."; 
    const char* ptr = str; 

    cout << str[0] << " " << *ptr << " t" << endl;

    ptr += 2;

    cout << ptr << " " << *(ptr + 2) << " " << *(ptr + 4) << endl;

    return 0;
}