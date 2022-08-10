#include<iostream>
using namespace std;

int main(){
    //int arr[]={5,20,14,-2,18};
    int arr[]={4,2,2,4,3,2};
    int n=sizeof(arr)/sizeof(int);
    int maxArr[n];
    maxArr[0]=arr[0];
    maxArr[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        maxArr[i]=max(arr[i]+maxArr[i-2],maxArr[i-1]);
    }

    cout<<"MAX sum subsequence : "<<maxArr[n-1];
}