#include <iostream>
#include <string>
using namespace std;

int main() {
    int *intArr = new int[3]{1, 2, 3};
    string *strArr = new string[2]{"Hello", "World"};
    
    for(int i = 0; i < 3; i++) cout << intArr[i] << " ";
    for(int i = 0; i < 2; i++) cout << strArr[i] << " ";
    
    delete[] intArr;
    delete[] strArr;
    return 0;
}
