#include <iostream>
using namespace std;

class Test {
public:
    void show() {
        cout << "Object created!" << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Test* arr = new Test[n];

    for (int i = 0; i < n; i++) {
        arr[i].show();
    }

    delete[] arr;
    return 0;
}
