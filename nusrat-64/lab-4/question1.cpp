#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;

    int *ptr = &a;
    cout << "Value using address: " << *ptr << endl;

    return 0;
}