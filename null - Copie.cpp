#include <iostream>
using namespace std;

void printValue(int* ptr) {

    if (ptr == nullptr) {
        cout << "Pointer is nullptr" << endl;  
    } else {
    
        cout << "Value: " << *ptr << endl;
    }
}

int main() {

    int num = 10;

    int* ptr = &num;

    cout << "Case 1: Pointer is not nullptr" << endl;
    printValue(ptr); 
    cout << endl;

    cout << "Case 2: Pointer is nullptr" << endl;
    int* nullPtr = nullptr; 
    printValue(nullPtr);  
    cout << endl;

    cout << "Case 3: Using dynamically allocated memory" << endl;
    int* dynamicPtr = new int(25);  
    printValue(dynamicPtr);  

    delete dynamicPtr;  
    cout << endl;

    cout << "Case 4: Pointer pointing to a local variable that goes out of scope" << endl;
    int* outOfScopePtr = nullptr;

    {
        int temp = 30;
        outOfScopePtr = &temp;  
        printValue(outOfScopePtr); 
    }

    printValue(outOfScopePtr);  

    cout << endl;

    cout << "Case 5: Pointer pointing to a constant value" << endl;
    const int constantValue = 50;
    const int* constPtr = &constantValue;  
    printValue(constPtr);  
    cout << endl;

    cout << "Case 6: Pointer becomes nullptr after being valid" << endl;
    int* temporaryPtr = new int(100);  
    cout << "Before setting to nullptr:" << endl;
    printValue(temporaryPtr);  

    temporaryPtr = nullptr;
    cout << "After setting to nullptr:" << endl;
    printValue(temporaryPtr); 
    cout << endl;

    cout << "Case 7: Array of integers" << endl;
    int arr[] = {5, 10, 15, 20, 25};
    int* arrPtr = arr;  
    printValue(arrPtr); 
    arrPtr++;  
    printValue(arrPtr);  
    cout << endl;

    return 0;
}