#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 2, 1, 1, 0, 0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int count_0 = 0, count_1 = 0, count_2 = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == 0) count_0++;
        else if(arr[i] == 1) count_1++;
        else if(arr[i] == 2) count_2++;
    }
    
    int i = 0;
    while(count_0 > 0) {
        arr[i++] = 0;
        count_0--;
    }
    
    while(count_1 > 0) {
        arr[i++] = 1;
        count_1--;
    }
    
    while(count_2 > 0) {
        arr[i++] = 2;
        count_2--;
    }
    
    cout << "Array elements after rearranging: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

