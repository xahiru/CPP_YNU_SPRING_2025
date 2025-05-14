#include <iostream>

using namespace std;

int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};

    int n = sizeof(arr) / sizeof(arr[0]);



    //using bubble sort to move all 0 to left and all 1 to right 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {     
                swap(arr[j], arr[j + 1]);

            }
    
        }
    
    }


    cout << "Array after divided: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;


}
