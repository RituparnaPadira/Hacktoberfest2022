#include<iostream>
using namespace std;
int main(){
    int n,i,x,count=0;
    cout<<"Enter array size: "<<endl;
    cin>>n;
    int a[20];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter any no: "<<endl;
    cin>>x;
    for(i=0;i<n;i++){
        if(x==a[i]){
            count++;
        }
    }
    if(count!=0){
    cout<<"No of time element present is "<<count<<endl;}
    else{
        cout<<"No element is present in array \n";
    }
    return 0;
}