#include<iostream>
using namespace std;

int countSubset(int n,int arr[],int target){
    int mat[n+1][target+1];

    for(int i=0;i<target+1;i++)
        mat[0][i]=0;
    for(int i=0;i<n+1;i++)
        mat[i][0]=1;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(arr[i-1]<=j){
                mat[i][j]=(mat[i-1][j-arr[i-1]]+mat[i-1][j]);
            }
            else{
                mat[i][j]=mat[i-1][j];
            }
        }
    }

    return mat[n][target];
}

int main(){
    int n=6;
    int arr[n]={2,3,5,6,8,10};
    int target=10;

    cout<<"No. of ways: "<<countSubset(n,arr,target);
}