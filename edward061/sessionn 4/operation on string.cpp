#include <iostream>
using namespace std;

int main() {
    const char* str = "A string."; 

    cout << str[0] << " " << (str + 1) << " " << *(str + 2) << endl;

    str = str + 2;
    cout << str << " " << str[1] << " " << str[3] << endl;

    return 0;
}