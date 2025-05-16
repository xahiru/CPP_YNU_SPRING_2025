#include <iostream>
using namespace std;

void updateVar(int* ptr) {
    *ptr += 10; 
}

int main() {
    int a = 4;
    updateVar(&a); 
    cout << a << endl; 

    a = 61;
    updateVar(&a); 
    cout << a << endl; 

    return 0;
}

