#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

template<typename T>
void sortArray(T arr[], int n) {
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int q = 1, n = 4; // Example for integer
    int arr[] = {123, -2311, 837, 0};
    sortArray(arr, n);

    return 0;
}
