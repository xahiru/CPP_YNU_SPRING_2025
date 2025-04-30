#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 22, 45, 11};
    int sum = 0;
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    double average = static_cast<double>(sum) / size;
    cout << "Average = " << average << endl;  
    return 0;
}
