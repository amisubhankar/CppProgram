#include<iostream>
#include<deque>
using namespace std;

void findMaxInK(int arr[],int n,int k){
    deque<int> dq;
    dq.push_back(0);
    //for 1st K-win size
    int j=1,i=0;
    while(j<k){
        if(arr[j]<arr[dq.back()]){
            dq.push_back(j);
        }
        else{
            while(dq.size()>0 && arr[j]>arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
        }
        j++;
    }
    cout<<arr[dq.front()]<<" ";
    while(j<n){
        //1st see whether i is in K-win range
        if(dq.front()==j-k)
            dq.pop_front();
        i++;
        //new j came
        //new element is lesser than deque last element
        if(arr[j]<arr[dq.back()]){
            dq.push_back(j);
        }
        //new element is larger than deque last element
        else{
            //pop till new element is larger 
            while(dq.size()>0 && arr[j]>arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
        }
        j++;
        //print max in K-win
        cout<<arr[dq.front()]<<" ";
    }
}

int main(){
    int arr[]={1,3,-1,-3,5,3,6,7};
    int n=sizeof(arr)/sizeof(int);

    findMaxInK(arr,n,3);
}