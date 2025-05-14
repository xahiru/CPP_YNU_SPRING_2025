#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = n; j > i + 1; --j) {
            cout << "  ";
        }
        for (char ch = 'A'; ch <= 'A' + i; ++ch) {
            cout << ch << " ";
        }
        for (char ch = 'A' + i - 1; ch >= 'A'; --ch) {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}