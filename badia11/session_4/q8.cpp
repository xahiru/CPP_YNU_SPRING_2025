#include <iostream>
using namespace std;

class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {}
};

int main() {
    MyClass *objects = new MyClass[3]{1, 2, 3};
    
    for(int i = 0; i < 3; i++) {
        cout << objects[i].value << " ";
    }
    
    delete[] objects;
    return 0;
}
