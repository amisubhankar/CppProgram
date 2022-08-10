#include<iostream>
#include<vector>
using namespace std;

void LCS(string x,string y,int n,int m,vector<vector<int>> &mat){
    for(int i=0;i<n+1;i++)
        mat[i][0]=0;
    for(int i=0;i<m+1;i++)
        mat[0][i]=0;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1])
                mat[i][j]=1+mat[i-1][j-1];
            else    
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    }
}

string printSCS(string x,string y,int n,int m){
    vector<vector<int>> mat(n+1,vector<int>(m+1));

    LCS(x,y,n,m,mat);
    
    string ans="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            ans=x[i-1]+ans;
            i--;
            j--;
        }
        else{
            if(mat[i][j-1]>=mat[i-1][j]){
                ans=y[j-1]+ans;
                j--;
            }
            else{
                ans=x[i-1]+ans;
                i--;
            }
        }
    }

    //as we've to traverse all the char in both string
    while(i>0){
        ans=x[i-1]+ans;
        i--;
    }
    while(j>0){
        ans=y[j-1]+ans;
        j--;
    }

    return ans;
}

int main(){
    string x="geek";
    string y="eke";
    int n=x.length();
    int m=y.length();

    cout<<"SCS = "<<printSCS(x,y,n,m);
}