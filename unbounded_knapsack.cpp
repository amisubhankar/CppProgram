#include<iostream>
#include<vector>
using namespace std;

int TKnapsack(int n,vector<int> w,vector<int> val,int W,vector<vector<int>> mat){
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0||j==0)  mat[i][j]=0; //for base condn
            else if(w[i-1]<=j){
                //just change here val[i-1]+mat[i][j-w[i-1]]
                //as if we take the element we can again take it
                mat[i][j]=max(val[i-1]+mat[i][j-w[i-1]],mat[i-1][j]);
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

    //Tabulation Procedure
    vector<vector<int>> mat(n+1,vector<int>(W+1));

    cout<<"Max Profit: "<<TKnapsack(n,w,val,W,mat);


}