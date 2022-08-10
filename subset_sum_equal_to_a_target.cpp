#include<iostream>
using namespace std;

bool subsetSum(int n,int arr[],int target){
    bool mat[n+1][target+1];
    
    //no elements so can't form any target
    for(int i=0;i<target+1;i++)
        mat[0][i]=false;
    //target=0 can easily form a subset having sum=0[empty subset]
    for(int i=0;i<n+1;i++)
        mat[i][0]=true;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(arr[i-1]<=j){
                //pick ||(or) not Pick
                mat[i][j]=(mat[i-1][j-arr[i-1]]) || (mat[i-1][j]);
            }
            else{
                //can't pick
                mat[i][j]=mat[i-1][j];
            }
        }
    }

    return mat[n][target];
}

int main(){
    int n=5;
    int arr[n]={2,3,7,8,10};
    int target=13;
    cout<<subsetSum(n,arr,target);
}