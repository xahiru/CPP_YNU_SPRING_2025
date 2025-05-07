#include <iostream>
using namespace std;

int main() {
    int a;

    cout << "Enter the value of a: ";
    cin >> a;

    int* ptr = &a;

    cout << "Output: " << *ptr << endl;

    return 0;
}
