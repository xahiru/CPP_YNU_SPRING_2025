#include<iostream>  
using namespace std;

int main(){
    int arr[8] = {7, 12, 9, 15, 19, 32, 56, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int firstMax, secondMax, thirdmax;
    firstMax = secondMax = thirdmax = 0;

    for(int i=0; i<=n; i++){
        if(arr[i]>firstMax){
            thirdmax = secondMax;
            secondMax = firstMax;
            firstMax = arr[i];
        }
        else if(arr[i]>secondMax && arr[i]!=firstMax){
            secondMax = arr[i];
        }
        else if( arr[i]>thirdmax && arr[i]!=secondMax && arr[i]!=firstMax){
            thirdmax = arr[i];
        }
    }

    cout<<"The largest integer is: "<<firstMax<<" ,"<<secondMax<<" ,"<<thirdmax<<endl;
}