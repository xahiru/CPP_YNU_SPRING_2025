#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a; 
    a = b;       
    b = temp;    
}

int main() {
    int A = 3;
    int B = 5;

    cout << "Before swapping: A = " << A << ", B = " << B << endl; 

    swap(A, B); 

    cout << "After swapping: A = " << A << ", B = " << B << endl; 
    return 0;
}