#include<iostream>
using namespace std;

bool isAllocationPossible(int arr[], int n, int mid, int m){
    int noOfStudents=1;
    int pagesAllocation=0;

    for(int i=0;i<n;i++){

        //if any of arr[i] is greater than mid then no allocation is possible 
        if(arr[i]>mid)
            return false;
        
        //check allocation cross the mid or not
        if(pagesAllocation+arr[i]>mid){
            noOfStudents++;//as current student allocation is full..so try with next student
            pagesAllocation=arr[i];//assign the book to next student..
        }   
        else{//allocation is not crossing mid so add this to current student..
            pagesAllocation+=arr[i];
        }
    }

    //check if solution is possible or not
    return (noOfStudents==m);
}

int binsearch(int arr[],int n,int m){
    int low=10000,high=0;
    for(int i=0;i<n;i++){
        if(arr[i]<low)
            low=arr[i];
        high+=arr[i];
    }

    int mid;
    int ans=-1;

    while(low<=high){
        mid=(high+low)/2; 

        if(isAllocationPossible(arr,n,mid,m)){
            ans=mid;
            high=mid-1;
            //cout<<"HI";
        }
        else
            low=mid+1;
       
    }

    return ans;
}

int main(){
    int arr[]={12,34,67,90};
    int n=sizeof(arr)/sizeof(int);
    int m=2;

    cout<<"Minimum allocation is : "<<binsearch(arr,n,m);

    return 0;

}