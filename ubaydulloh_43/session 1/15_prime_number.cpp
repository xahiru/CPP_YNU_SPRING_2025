#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int num,count=1;
    cout<<"Number to check = ";
    cin>>num;  

    if(num<=1){
        count=0;
    }
    else{
        for(int i=2; i<sqrt(num); i++){
            if(num%i==0){
                count = 0;
                break;
            }
        }
    }

    if(count==0)
        cout<<num<<" is not a prime number"<<endl;
    else 
        cout<<num<<" is a prime number"<<endl;
    
    
    return 0;
}