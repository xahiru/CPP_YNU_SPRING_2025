#include <iostream>
using namespace std;

int main (){
    int a;
    int *ptr = &a;

    cout << "a is:" << endl;
    cin >> a;

    cout << *ptr << endl;
    cout << ptr << endl;
    
    return 0;
}
