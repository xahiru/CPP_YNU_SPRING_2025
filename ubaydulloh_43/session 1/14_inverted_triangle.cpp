#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the length of the triangle = ";
    int num, space = 0;
    cin>>num;

    for(int i= num; i>0; i--){
        for(int j=i*2; j>0; j--){
            cout<<"*";            
        }
        if(i==1){
            cout<<endl;
            for(int l=0; l<num; l++){
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<endl;
        space++;
        for(int k=0; k<space; k++){
            cout<<" ";
        }
    }
    return 0;
}