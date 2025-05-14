#include <iostream>
using namespace std;

class MyClass {
public:
    int value;
    MyClass(int val) : value(val) {}
};

int main() {
    int size = 5;
    MyClass* objArray = new MyClass[size] {1, 2, 3, 4, 5};

    for (int i = 0; i < size; ++i) {
        cout << "Object " << i << " value: " << objArray[i].value << endl;
    }

    delete[] objArray;

    return 0;
}