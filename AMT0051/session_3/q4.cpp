#include <iostream>
using namespace std;

void separateZerosAndOnes(int arr[], int size) {
    int count = 0; 

 
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
            count++;
    }


    for (int i = 0; i < count; i++)
        arr[i] = 0;


    for (int i = count; i < size; i++)
        arr[i] = 1;
}

int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    separateZerosAndOnes(arr, size);

    cout << "Array after divided: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
