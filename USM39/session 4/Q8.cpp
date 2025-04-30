#include <iostream>
using namespace std;

class MyObject {
public:
    int value;
    MyObject(int v) : value(v) {}
};

int main() {
    int size = 3;
    MyObject *objArray = new MyObject[size] {1, 2, 3};

    for (int i = 0; i < size; i++) {
        cout << objArray[i].value << endl;
    }

    delete[] objArray;
    return 0;
}
