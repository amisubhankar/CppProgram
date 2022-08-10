#include<iostream>
using namespace std;

int coinChange(int n,int coin[],int sum){
    int mat[n+1][sum+1];

    for(int i=0;i<sum+1;i++)
        mat[0][i]=INT8_MAX-1;
    for(int i=0;i<n+1;i++)
        mat[i][0]=0;

    //initialize 2nd row
    for(int i=1;i<sum+1;i++){
        if(i%coin[0]==0)
            mat[1][i]=i/coin[0];
        else
            mat[1][i]=INT8_MAX-1;
    }

    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                mat[i][j]=min(1+mat[i][j-coin[i-1]],mat[i-1][j]);
            }
            else{
                mat[i][j]=mat[i-1][j];
            }
        }
    }

    return mat[n][sum];
    
}

int main(){
    int n=3;
    int coin[n]={25,10,5};
    int sum=30;

    cout<<"Min no. of coin needed : "<<coinChange(n,coin,sum);
}