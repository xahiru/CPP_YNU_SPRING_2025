#include <iostream>
using namespace std;

int i[5] = {0, 2, 4, 6, 8};
int* p;

void foo() {
    cout << *p << endl;
    ++(*p);
    ++p;
}

void bar() {
    for (int i = 0; i < 3; ++i) {
        foo();
    }
}

int main() {
    p = i;          // Point to the start of the array
    bar();           // Call `foo()` 3 times
    cout << "Check Point 1" << endl;
    p = i;          // Reset pointer to the start of the array
    foo();           // Call `foo()` once more
    cout << "Check Point 2" << endl;
    return 0;
}