#include<iostream>
using namespace std;

string PLCS(int n,int m,string x,string y){
    string mat[n+1][m+1];

    for(int i=0;i<n+1;i++)
        mat[i][0]="";
    for(int i=0;i<m+1;i++)
        mat[0][i]="";
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                mat[i][j]=mat[i-1][j-1]+x[i-1];
            }
            else{
                if(mat[i-1][j].length()>mat[i][j-1].length())
                    mat[i][j]=mat[i-1][j];
                else
                    mat[i][j]=mat[i][j-1];
            }
        }
    }

    return mat[n][m];
}

int main(){
    string x="abcdrh";
    string y="bcdfrgh";
    int n=x.length();
    int m=y.length();

    cout<<"Longest Common Subsequence : "<<PLCS(n,m,x,y);
}