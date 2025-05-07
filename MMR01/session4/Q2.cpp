#include <iostream>
using namespace std;

void updateVar(int *a) {
    *a += 10;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    cout << "Before update: " << num << endl;
    updateVar(&num);  // Pass the address of num
    cout << "After update: " << num << endl;
    
    return 0;
}