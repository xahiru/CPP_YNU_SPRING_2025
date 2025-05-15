#include <iostream>
#include <string>
using namespace std;

int main() {
    float **floatArr = new float*[2];
    for(int i = 0; i < 2; i++) {
        floatArr[i] = new float[2]{1.1f, 2.2f};
    }
    
    string **strArr = new string*[2];
    for(int i = 0; i < 2; i++) {
        strArr[i] = new string[2]{"A", "B"};
    }
    
    // Cleanup
    for(int i = 0; i < 2; i++) {
        delete[] floatArr[i];
        delete[] strArr[i];
    }
    delete[] floatArr;
    delete[] strArr;
    
    return 0;
}
