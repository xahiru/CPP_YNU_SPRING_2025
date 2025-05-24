#include <iostream>
using namespace std;

void swapValues(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 3, b = 5;
    swapValues(a, b);  
    
    cout << a << " " << b << endl;  
    
    return 0;
}