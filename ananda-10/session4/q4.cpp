#include <iostream>
using namespace std;

void swapValues(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 3, b = 5;
    swapValues(&a, &b); 
    cout << a << " " << b << endl; 
    return 0;
}

