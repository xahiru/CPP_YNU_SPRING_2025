#include <iostream>
using namespace std;

int sum_from_to(int first, int last) {
    int sum = 0;
    
    if (first > last) {
        swap(first, last);
    }

    for (int i = first; i <= last; i++) {
        sum += i;
    }

    return sum;
}

int main() {

    cout << sum_from_to(4, 7) << endl;   
    cout << sum_from_to(3, 1) << endl;  
    cout << sum_from_to(9, 6) << endl;  
    cout << sum_from_to(10, 9) << endl; 

    return 0;
}