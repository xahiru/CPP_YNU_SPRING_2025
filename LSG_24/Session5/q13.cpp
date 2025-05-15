#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3};
    cout << "Array: [1, 2, 3]" << endl;
    
    // Double each element using reference
    for (int& num : arr) {
        num *= 2;
    }
    
    cout << "Doubled Array: [";
    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        cout << arr[i];
        if (i < sizeof(arr)/sizeof(arr[0]) - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}