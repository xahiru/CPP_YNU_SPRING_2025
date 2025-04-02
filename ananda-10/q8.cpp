#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    cout << max(max(a, b), c) << " is the largest." << endl;

    return 0;
}
