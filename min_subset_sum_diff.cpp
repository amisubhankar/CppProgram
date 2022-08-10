#include<iostream>
#include<vector>
using namespace std;

int subsetSum(int n,int arr[],int target){
    bool mat[n+1][target+1];
    for(int i=0;i<target+1;i++)
        mat[0][i]=false;
    for(int i=0;i<n+1;i++)
        mat[i][0]=true;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(arr[i-1]<=j){
                mat[i][j]=(mat[i-1][j-arr[i-1]] || mat[i-1][j]);
            }
            else{
                mat[i][j]=mat[i-1][j];
            }
        }
    }

    //storing the last row of dp matrix upto target/2
    vector<int> range;
    for(int i=0;i<=target/2;i++)
    {
        if(mat[n][i])   range.push_back(i);
    }

    //as last element of the array is highest subset sum possible in partition 1 
    return target-(2*range.back());
}

int main(){
    int n=4;
    int arr[n]={1,2,7,10};

    //calculating total sum of array
    int sum=0;
    for(int i:arr)
        sum+=i;
    
    cout<<"Min subset sum diff: "<<subsetSum(n,arr,sum);
}