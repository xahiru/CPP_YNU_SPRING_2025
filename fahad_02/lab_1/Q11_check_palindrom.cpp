#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int num,count=1;
    cout<<"Number to check = ";
    cin>>num;  
    
    int temp = num;
    int reversed = 0;
    while(temp!=0){
        reversed = reversed *10 + (temp%10);
        temp /= 10;
    }
    
    if(num==reversed)
        cout<<num<<" is a palindrom number."<<endl;
    else    
        cout<<num<<" is not a palindrom number."<<endl;
    
    return 0;
}