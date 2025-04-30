#include <iostream>
using namespace std;

int main() {
    int A = 4;
    cout << "Value of A: " << A << endl;
    cout << "Address of A: " << &A << endl;

    A = 6;  
    cout << "New value of A: " << A << endl; 
    cout << "Address of A: " << &A << endl; 

    return 0;
}