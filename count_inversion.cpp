//Array 16)
#include<iostream>
using namespace std;

int merge(int arr[],int temp[],int low,int mid,int high){
    int count=0;

    int i=low;
    int j=mid;
    int k=low;

    while(i<=mid-1 && j<=high){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            count+=(mid-i);
            temp[k++]=arr[j++];
        }
    }

    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=high)
        temp[k++]=arr[j++];

    for(int i=low;i<=high;i++)
        arr[i]=temp[i];
    
    return count;
}

int countInversion(int arr[],int temp[],int low,int high){
    int count=0,mid;
    if(high>low){
        mid=(low+high)/2;

        count+=countInversion(arr,temp,low,mid);
        count+=countInversion(arr,temp,mid+1,high);

        count+=merge(arr,temp,low,mid+1,high);
    }

    return count;
}

int main(){
    int arr[]={1,2,5,4,3};
    int n=sizeof(arr)/sizeof(int);
    int temp[n];
    int count=countInversion(arr,temp,0,n-1);

    cout<<"Inversion count is: "<<count;

    return 0;
}