#include <iostream>
using namespace std;

void updateVar(int *a) {

    *a += 10;
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