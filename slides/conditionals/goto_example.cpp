// C++ program to demonstrate the use of goto statement

#include <iostream>
using namespace std;

int main()
{

    int age = 17;
    if (age < 18) {
        goto Noteligible;
    }
    else {
        cout << "You can vote!";
    }
Noteligible:
    cout << "You are not eligible to vote!\n";
    return 0;
}