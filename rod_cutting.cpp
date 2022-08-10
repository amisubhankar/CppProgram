#include<iostream>
#include<vector>
using namespace std;

int cutRod(int price[], int n) {
    int mat[n+1][n+1];
        
    //creating length array
    int length[n];
    for(int i=1;i<n+1;i++)
        length[i-1]=i;
        
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0||j==0) mat[i][j]=0;
            else if(length[i-1]<=j){
                mat[i][j]=max(price[i-1]+mat[i][j-length[i-1]],mat[i-1][j]);
            }
            else{
                mat[i][j]=mat[i-1][j];
            }
        }
    }
    return mat[n][n];
}

int main(){
    int n=8; //no of elements
    int price[n]={1, 5, 8, 9, 10, 17, 17, 20};// piece[2]+piece[6]=5+17=22

    cout<<"Max Profit: "<<cutRod(price,n);

}

/*
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
Output: 24
Explanation: 
The maximum obtainable value is 
24 by cutting the rod into 8 pieces 
of length 1, i.e, 8*3=24
*/