#include <iostream>
using namespace std;

int main() {
    int n;
    do {
        cout << "Enter a number (0 to exit): ";
        cin >> n;
        cout << "You entered: " << n << endl;
    } while (n != 0);

    return 0;
}