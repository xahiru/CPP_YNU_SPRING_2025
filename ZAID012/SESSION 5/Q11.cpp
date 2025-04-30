#include <iostream>
using namespace std;

void printPyramid(int n) {
    for (int i = 0; i < n; ++i) {
        char ch = 'A';
        for (int j = 0; j <= i; ++j) {
            cout << ch << " ";
            ch++;
        }
        for (int j = i - 1; j >= 0; --j) {
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;
    printPyramid(n);
    return 0;
}