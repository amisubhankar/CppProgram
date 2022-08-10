//This is actually Kadane's algo

#include<iostream>
#include<vector>
using namespace std;

int kadane(vector<int> arr){
    int sum=0;
    int maxSum=INT8_MIN;
    int strt,end;

    for(auto item : arr){
        sum+=item;
        maxSum=max(sum,maxSum);
        sum=(sum<0)?0:sum;
    }

/*  if u want to print subarray index then follow this..

    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>maxSum){
            maxSum=sum;
            end=i;
        }
        sum=(sum<0)?0:sum;
    }

    int temp=maxSum;
    strt=end;
    while(temp!=0){
        temp-=arr[strt--];
    }

    
    cout<<"Start= "<<strt+1<<endl;
    cout<<"End= "<<end<<endl;
*/


    return maxSum;
}

int main(){
    vector<int> arr={-2,4,-1,2,1,-8,16,-5,4};

    cout<<"Maximum subarray sum is: "<<kadane(arr);

    return 0;
}