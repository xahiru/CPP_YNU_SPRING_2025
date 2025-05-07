#include <iostream>
using namespace std;

void updateVar(int *a) {
    *a += 10; 
}

int main() {
    int A = 4;
    cout << "Initial value of A: " << A << endl; 

    updateVar(&A); 

    cout << "Value of A after update: " << A << endl; 
    return 0;
}