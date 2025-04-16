#include<iostream>  
using namespace std;

int main(){
    int arr[7] = {5, 6, 7, 2, 3, 4, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int firstSmall, secondSmall;
    firstSmall = secondSmall =  20;

    for(int i=0; i<n; i++){
        if(arr[i]<firstSmall){
            firstSmall = arr[i];
        }
        else if(arr[i]<secondSmall && arr[i]!=firstSmall){
            secondSmall = arr[i];
        }
    }

    cout<<"The largest integer is: "<<firstSmall<<" ,"<<secondSmall<<endl;
}