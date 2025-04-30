#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int count_zeros = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == 0) {
            count_zeros++;
        }
    }
    
    for(int i = 0; i < size; i++) {
        if(i < count_zeros) {
            arr[i] = 0;
        } else {
            arr[i] = 1;
        }
    }
    
    cout << "Array after divided: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

