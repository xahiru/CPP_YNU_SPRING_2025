#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Input the number upto: ";
    cin >> n;

    cout << "Multiplication table from 1 to " << n << endl;

    for (int i = 1; i <= 10; i++) {  
        for (int j = 1; j <= n; j++) {  
            cout << j << "x" << i << "=" << j * i << "\t";
        }
        cout << endl;
    }

    return 0;
}

