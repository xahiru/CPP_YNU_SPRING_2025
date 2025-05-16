#include <iostream>
using namespace std;

void showValue(const int* numberPtr) {
    if (!numberPtr) {
        cout << "Pointer is nullptr" << endl;
        return;
    }
    cout << "Value: " << *numberPtr << endl;
}

int main() {
    int num = 10;
    int* pNull = nullptr;
    int* pValid = &num;

    showValue(pNull);
    showValue(pValid);

    return 0;
}
