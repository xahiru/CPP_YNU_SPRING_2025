#include<iostream>
using namespace std;

void dynamic(int a[], int len, string b){
    cout<<"array = ";
    for(int i=0; i<len; i++){
        cin>>a[i];
    }
    cout<<"string = ";
    cin>>b;
    for(int i=0; i<len; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<b<<endl;
}
int main(){
    int len;
    cout<<"len = ";
    cin>>len;
    int a[len];
    string b;
    dynamic(a,len,b);
}