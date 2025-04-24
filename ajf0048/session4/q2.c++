#include <iostream>
using namespace std;

void updateVar(int *a){
    *a += 10;;
}

int main(){
    int a;
    int *ptr = &a;

    cin >> a;
    cout << "Before update: " << a << endl;

    updateVar(ptr);

    cout << "After update: " << a << endl;

    return 0;
}