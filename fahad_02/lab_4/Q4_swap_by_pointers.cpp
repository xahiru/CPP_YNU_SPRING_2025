#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int *ptr = &a;
    a = b;
    b = *ptr;
    cout<<"a = "<<a<<", b = "<<b<<endl;
}