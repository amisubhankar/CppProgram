#include<iostream>
#include<vector>
using namespace std;

int rKnapsack(int n,vector<int> w,vector<int> val,int W){
    //Base condn
    if(n==0 || W==0)    return 0;

    //pick up possible
    if(w[n-1]<=W){
        //max of(when pick , when not pick)
        return max(val[n-1]+rKnapsack(n-1,w,val,W-w[n-1]),
                    rKnapsack(n-1,w,val,W));
    }
    else{
        return rKnapsack(n-1,w,val,W);
    }
}

int MKnapsack(int n,vector<int> w,vector<int> val,int W,vector<vector<int>> &mat){
    //Base condn
    if(n==0 || W==0)    return 0;

    //Memoization step
    if(mat[n][W]!=-1)   return mat[n][W];

    //pick up possible
    if(w[n-1]<=W){
        //max of(when pick , when not pick)
        mat[n][W]=max(val[n-1]+rKnapsack(n-1,w,val,W-w[n-1]),
                    rKnapsack(n-1,w,val,W));
    }
    else{
        mat[n][W]= rKnapsack(n-1,w,val,W);
    }

    return mat[n][W];
    
}

int TKnapsack(int n,vector<int> w,vector<int> val,int W,vector<vector<int>> mat){
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0||j==0)  mat[i][j]=0; //for base condn
            else if(w[i-1]<=j){
                mat[i][j]=max(val[i-1]+mat[i-1][j-w[i-1]],mat[i-1][j]);
            }
            else{
                mat[i][j]=mat[i-1][j];
            }
            
        }
    }

    return mat[n][W];
}

int main(){
    int n=4; //no of elements
    vector<int> w={1,3,4,5}; //weight array
    vector<int> val={10,40,50,70}; //value array
    int W=8; //Knapsack capacity

    //Recursion Procedure
    //cout<<"Max Profit: "<<rKnapsack(n,w,val,W);

    // //Memoization Procedure
    // vector<vector<int>> mat(n+1,vector<int>(W+1,-1));

    // cout<<"Max Profit: "<<MKnapsack(n,w,val,W,mat);

    //Tabulation Procedure
    vector<vector<int>> mat(n+1,vector<int>(W+1));

    cout<<"Max Profit: "<<TKnapsack(n,w,val,W,mat);


}