#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 12;
    cout << std::setw(5);          // Set width to 5
    cout << std::setfill('*');     // Set fill character to '*'
    cout << a << "\n";             // ***12
    cout << std::setw(5);
    cout << "Hi" << "\n";          // ***Hi
    cout << std::left;             // Left-align the output
    cout << std::setw(5);
    cout << a << "\n";             // 12***
    return 0;
}