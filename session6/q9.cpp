#include <iostream>
using namespace std;

int main() {
    char c1, c2;

    cout << "Enter starting character (c1): ";
    cin >> c1;
    cout << "Enter ending character (c2): ";
    cin >> c2;

    for (char ch = c1; ch <= c2; ch++) {
        cout << ch << " ";
    }

    return 0;
}

