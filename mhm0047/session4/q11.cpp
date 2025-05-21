#include <iostream>
using namespace std;

int main() {
    const char* ptr = "A string.";

    cout << *(ptr + 0) << " " << ptr[0] << " " << *(ptr + 3) << endl;

    ptr = ptr + 2;

    cout << *ptr << " " << *(ptr + 1) << " " << *(ptr + 3) << endl;

    return 0;
}
