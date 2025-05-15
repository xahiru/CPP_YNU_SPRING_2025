#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 250, temp;
    temp = a;
    a = b;
    b = temp;
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}