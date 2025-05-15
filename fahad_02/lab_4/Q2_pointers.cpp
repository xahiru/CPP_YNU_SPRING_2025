#include<iostream>
using namespace std;

void updateVar(int *a){
    *a +=10;
}

int main()
{
    int a;
    cin>>a;
    updateVar(&a);
    cout<<a<<endl;
}