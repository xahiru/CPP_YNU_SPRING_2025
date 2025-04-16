#include <iostream>
using namespace std;

int sum_from_to(int first, int last) {

    int low = (first < last) ? first : last;
    int high = (first > last) ? first : last;


    int n = high - low + 1;
    return n * (low + high) / 2;
}

int main() {
    cout << sum_from_to(4,7) << endl;   // 22
    cout << sum_from_to(-3,1) << endl;  // -5
    cout << sum_from_to(7,4) << endl;   // 22
    cout << sum_from_to(9,9) << endl;   // 9
    
    return 0;
}