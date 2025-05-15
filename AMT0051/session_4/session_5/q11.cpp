#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;

    if (n >= 26 || n < 1) {
        cout << "Please enter a number between 1 and 25." << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        
        for (int j = 0; j < n - i - 1; ++j)
            cout << "  ";

        for (int j = 0; j <= i; ++j)
            cout << char('A' + j) << " ";

        for (int j = i - 1; j >= 0; --j)
            cout << char('A' + j) << " ";

        cout << endl;
    }

    return 0;
}
