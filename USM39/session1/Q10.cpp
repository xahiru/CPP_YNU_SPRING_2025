#include <iostream>
using namespace std;

int main() {
    int num, isPrime = 1;
    cout << "Enter a number: ";
    cin >> num;

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if (isPrime && num > 1)
        cout << num << " is Prime Ok." << endl;
    else
        cout << num << " is not Prime Ok." << endl;
    return 0;
}