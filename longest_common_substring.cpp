#include<iostream>
using namespace std;

int LCString(int n,int m,string x,string y){
    int mat[n+1][m+1];

    for(int i=0;i<n+1;i++)
        mat[i][0]=0;
    for(int i=0;i<m+1;i++)
        mat[0][i]=0;
    
    int maxLength=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                mat[i][j]=1+mat[i-1][j-1];
                maxLength=max(maxLength,mat[i][j]);
            }
            else{
                mat[i][j]=0;
            }
        }
    }

    return maxLength;
}

int main(){
    string x="abcdegh";
    string y="abcdehr";
    int n=x.length();
    int m=y.length();

    cout<<"Length of Longest Common SubString : "<<LCString(n,m,x,y);
}