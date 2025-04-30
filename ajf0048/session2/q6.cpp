#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << number << " is ";
    if (number % 2 == 0) {
        cout << "even." << endl;
    } else {
        cout << "odd." << endl;
    }
    return 0;
}