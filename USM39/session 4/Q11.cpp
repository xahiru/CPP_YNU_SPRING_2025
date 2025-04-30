#include <iostream>
using namespace std;

int main() {
    string str = "A string.";
    char *ptr = &str[0];

    cout << ptr[0] << " " << ptr << " " << ptr[2] << endl; 
    ptr += 2;
    cout << ptr << " " << ptr[2] << " " << ptr[4] << endl;
    return 0;
}
