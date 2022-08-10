#include<iostream>
using namespace std;

int numberOfPaths(int m, int n){
    int mat[m][n]={0};
    mat[m-1][n-1]=0;
    //put 1 at last col
    for(int i=0;i<m;i++)
        mat[i][n-1]=1;
    //put 1 at last row
    for(int i=0;i<n;i++)
        mat[m-1][i]=1;
        
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            mat[i][j]=(mat[i+1][j]+mat[i][j+1]);
        }
    }
        
    return mat[0][0];
}

int main(){
    cout<<"No. of paths from (0,0) cell to (m-1,n-1) cell : "<<numberOfPaths(4,4);
}