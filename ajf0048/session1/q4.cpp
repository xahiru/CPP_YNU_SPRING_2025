#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout << "// Enter two numbers: " << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cin >> a >> b;
    int temp = a;
    a=b;
    b=temp;
    cout << "After swapping: " << a << " and " << b << endl;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}