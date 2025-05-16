#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input the number upto: ";
    cin >> n;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << j << "x" << i << "=" << j*i << " ";
        }
        cout << endl;
    }
    return 0;
}