#include <iostream>
using namespace std;

int main() {
    int num;
    
    cout << "Enter an Number: "; //ask enter an number
    cin >> num;

    if (num & 1) {
        cout << num << " is odd." << endl; //check the enter number is odd
    } else {
        cout << num << " is even." << endl; //check the enter number is even
    }

    return 0;
}