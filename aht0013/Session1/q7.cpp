#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num % 2 == 0) {
        cout << num << " is an Even Number." << endl;
    } else {
        cout << num << " is an Odd Number." << endl;
    }

    return 0;
}