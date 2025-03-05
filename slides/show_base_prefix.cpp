#include <iostream>
using namespace std;

int main()
{
    int a = 26;
    cout << std::showbase;
    cout << std::oct;
    cout << a << "\n";  // 032
    cout << std::hex;
    cout << a << "\n";  // 0x1a
    cout << std::showbase;
    cout << a << "\n";  // +0x1a
    cout << std::uppercase;
    cout << a << "\n";  // +0X1A
    return 0;
}