#include <iostream>
#include <string>
using namespace std;

int main() {
    int *intArr = new int[3]{1, 2, 3};
    string *strArr = new string[2]{"Hello", "World"};
    
    delete[] intArr;
    delete[] strArr;
    return 0;
}