//Array 7)
#include<iostream>
#include<algorithm>

using namespace std;

void swap(int *a, int *b){
    int *t=a;
    a=b;
    b=t;
}

int main(){
    int arr[]={4,3,2,1};
    int n=sizeof(arr)/sizeof(int);

    int i;
    for(i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1])
            break;
    }
    
    if(i==-1){
        for(i=n-1;i>=0;i--)
            cout<<arr[i];
        return 0;
    }
    

    int max=arr[i+1];
    int pos=i+1;
    for(int j=i+2;j<n;j++){
        if(arr[j]>arr[i] && arr[j]<max){
            max=arr[j];
            pos=j;
        }
    }
    

    swap(arr[i],arr[pos]);

    sort(arr+i+1,arr+n);

    for(i=0;i<n;i++)
        cout<<arr[i];

}