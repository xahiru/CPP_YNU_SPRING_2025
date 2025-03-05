#include <iostream>
using namespace std;

int main()
{
    int a = 26, b = 20;
    cout << a << " " << b << "\n";  // 26 20
    cout << std::hex;
    cout << a << " " << b << "\n";  // 1a 14
    cout << std::oct;
    cout << a << " " << b << "\n";  // 32 24
    cout << std::dec;
    cout << a << " " << b << "\n";  // 26 20
    return 0;
}