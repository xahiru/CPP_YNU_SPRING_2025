#include <iostream>
#include <string>
using namespace std;

void fun(int* a, int len, string b) {
    cout << "Enter elements of the array: ";
    for(int i = 0; i < len; i++) {
        cin >> a[i];  
    }
    
    cout << "Enter a string: ";
    cin >> b;  
    
    cout << "Array = ";
    for(int i = 0; i < len; i++) {
        cout << a[i] << " ";  
    }
    
    cout << endl << "String = " << b << endl;  
}

int main() {
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;  
    
    int* a = new int[len];  
    string b;  
    
    fun(a, len, b);
    
    delete[] a;  
    
    return 0;
}
