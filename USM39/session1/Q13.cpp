#include <iostream>
using namespace std;

int main() {
    int num, fact = 1;
    cout << "Enter a number: ";
    cin >> num;

    for (int i = 1; i <= num; i++)
        fact *= i;

    cout << "Factorial of " << num << " = " << fact << endl;
    return 0;
}