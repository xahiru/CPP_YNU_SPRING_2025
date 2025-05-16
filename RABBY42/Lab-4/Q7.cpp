#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows = 2, cols = 2;
    float **floatArr = new float*[rows];
    string **strArr = new string*[rows];
    
    for (int i = 0; i < rows; ++i) {
        floatArr[i] = new float[cols]{1.1f, 2.2f};
        strArr[i] = new string[cols]{"Hello", "World"};
    }
    
    // Cleanup
    for (int i = 0; i < rows; ++i) {
        delete[] floatArr[i];
        delete[] strArr[i];
    }
    delete[] floatArr;
    delete[] strArr;
    return 0;
}