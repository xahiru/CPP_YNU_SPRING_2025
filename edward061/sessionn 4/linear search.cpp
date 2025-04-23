#include <iostream>
using namespace std;

int main() {

    int arr[] = {10, 11, 7, 8, 2, 9};

    int searchElement = 19;

    int n = sizeof(arr) / sizeof(arr[0]);

    int index = -1;  

    for (int i = 0; i < n; ++i) {
        if (arr[i] == searchElement) {
            index = i;  
            break;
        }
    }

    if (index != -1) {
        cout << "Element " << searchElement << " found at index " << index << endl;
    } else {
        cout << searchElement << " not found in the array" << endl;
    }
    
    return 0;
}