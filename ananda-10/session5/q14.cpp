#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3};

    cout << "Array: [";
    for (const int& x : arr) {
        cout << x << (x != arr[2] ? ", " : "");
    }
    cout << "]" << endl;

  
    for (int& x : arr) {
        x *= 2;
    }

    cout << "Doubled Array: [";
    for (const int& x : arr) {
        cout << x << (x != arr[2] ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}

