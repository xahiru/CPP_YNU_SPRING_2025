#include <iostream>
using namespace std;



int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;

    auto updateVar = [](int* ptr) {
        *ptr += 10;
    };

    updateVar(&a); 

    cout << "Updated value of a is : " << a << endl;

    return 0;
}
