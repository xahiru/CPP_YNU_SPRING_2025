#include <iostream>
using namespace std;

int main() {
    // Get the sizes of different data types
    size_t intSize = sizeof(int);
    size_t floatSize = sizeof(float);
    size_t doubleSize = sizeof(double);
    size_t charSize = sizeof(char);

    // Print the sizes
    cout << "size of int: " << intSize << " bytes" << endl;
    cout << "size of float: " << floatSize << " bytes" << endl;
    cout << "size of double: " << doubleSize << " bytes" << endl;
    cout << "size of char: " << charSize << " bytes" << endl;

    return 0;
}