#include<iostream>
using namespace std;

int main(){
    cout<<"Enter a number = ";
    int num, sum=1;
    cin>>num;
    for(int i=1; i<=num; i++){
        sum *=i;
    }
    cout<<"Factorial is = "<<sum<<endl;
    return 0;
}