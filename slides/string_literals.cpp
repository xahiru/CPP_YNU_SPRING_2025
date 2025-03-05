#include <iostream>
using namespace std;

int main()
{
    cout << "Character and String Literals\n";
    {
        char c = 'g';
        const char *s1 = "ynu";
        string s2 = "courses";
        cout << c << "\n"
            << s1 << "\n"
            << s2 << "\n";
    }
    return 0;
}