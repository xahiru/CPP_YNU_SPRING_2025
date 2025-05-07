#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter a value: ";
    cin >> a;

    int* ptr = &a;  

    cout << "Output: " << *ptr << endl;

    return 0;
}
