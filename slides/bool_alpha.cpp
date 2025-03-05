#include <iostream>
using namespace std;

int main()
{
    bool a = true;
    cout << a << "\n";        // 1
    cout << std::boolalpha;   // Set output to true/false
    cout << a << "\n";        // true
    cout << std::noboolalpha; // Set output back to 0/1
    cout << a;                // 1

    return 0;
}