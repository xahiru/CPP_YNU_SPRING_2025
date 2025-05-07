#include <iostream>
using namespace std;


void updateVar(int* ptr) {
    *ptr += 10;
}

int main() {
    int a;

    cout << "Enter the value of a: ";
    cin >> a;

    updateVar(&a);

    cout << "Output: " << a << endl;

    return 0;
}
