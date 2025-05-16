#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) arr[i] = (i+1)*(i+1);
    cout << "Squares: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    delete[] arr;
    return 0;
}