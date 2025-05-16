#include <iostream>
using namespace std;

void updateVar(int *a) {
    *a += 10; // Equivalent to *a = *a + 10;
}

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;

    updateVar(&a); // Pass address of 'a'

    cout << "Updated value: " << a << endl;
    return 0;
}