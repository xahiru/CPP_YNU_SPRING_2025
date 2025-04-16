#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Number = ";
    cin >> number;
    if (number % 2 == 0)
        cout << number << " is Even Number." << endl;
    else
        cout << number << " is Odd Number." << endl;
    return 0;
}
