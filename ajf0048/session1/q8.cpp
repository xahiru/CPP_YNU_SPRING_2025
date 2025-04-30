#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three numbers: " << endl;
    cin >> a >> b >> c;
    cout << "You entered: " << a << ", " << b << ", " << c << endl;
    
    if (a > b && a > c)
        cout << a << " is the largest." << endl;
    else if (b > a && b > c)
        cout << b << " is the largest." << endl;
    else
        cout << c << " is the largest." << endl;
    return 0;
}