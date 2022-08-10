#include<iostream>
#include<vector>
using namespace std;

int rLCS(int n,int m,string x,string y){
    //Base condn
    if(n==0||m==0)  return 0;
    
    //Last element equal
    if(x[n-1]==y[m-1]){
        return 1+rLCS(n-1,m-1,x,y);
    }
    //last element not equal
    else{
        return max(rLCS(n,m-1,x,y),rLCS(n-1,m,x,y));
    }
}

int mLCS(int n,int m,string x,string y,vector<vector<int>> &mat){
    //Base condn
    if(n==0||m==0)  return 0;
    
    //Memoization step added
    if(mat[n][m]!=-1)   return mat[n][m];

    //Last element equal
    if(x[n-1]==y[m-1]){
        mat[n][m] = 1+rLCS(n-1,m-1,x,y);
    }
    //last element not equal
    else{
        mat[n][m] = max(rLCS(n,m-1,x,y),rLCS(n-1,m,x,y));
    }

    return mat[n][m];
}

int tLCS(int n,int m,string x,string y){
    int mat[n+1][m+1];

    for(int i=0;i<n+1;i++)
        mat[i][0]=0;
    for(int i=0;i<m+1;i++)
        mat[0][i]=0;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                mat[i][j]=1+mat[i-1][j-1];
            }
            else{
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }

    return mat[n][m];
}

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

    //Recursive approach
    //cout<<"Length of Longest Common Subsequence : "<<rLCS(n,m,x,y);

    //Memoization approach
    // vector<vector<int>> mat(n+1,vector<int>(m+1,-1));
    // cout<<"Length of Longest Common Subsequence : "<<mLCS(n,m,x,y,mat);

    //Tabulation approach
    //cout<<"Length of Longest Common Subsequence : "<<tLCS(n,m,x,y);

    cout<<"Longest Common Subsequence : "<<PLCS(n,m,x,y);
}