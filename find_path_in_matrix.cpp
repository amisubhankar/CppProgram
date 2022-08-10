//graph 4)
#include<iostream>
#include<vector>
#define n 5
using namespace std;

bool findPath(int mat[][n],int r,int c,vector<pair<int,int>> &ans){
    if(r==n-1 && c==n-1){
        ans.push_back({r,c});
        return true;
    }
    else if(r<0 || c<0 || r>n-1 || c>n-1 || mat[r][c]==0){
        return false;
    }
    ans.push_back({r,c});
    mat[r][c]=0;
    if( findPath(mat,r-1,c,ans) )   return true;
    if( findPath(mat,r,c+1,ans) )   return true;
    if( findPath(mat,r+1,c,ans) )   return true;
    if( findPath(mat,r,c-1,ans) )   return true;
    mat[r][c]=1;
    ans.pop_back();
    return false;
}

int main(){
    int mat[n][n]={ {1, 0, 0, 0, 0},
                    {1, 0, 1, 1, 1},
                    {1, 1, 1, 0, 1},
                    {1, 0, 0, 0, 1},
                    {1, 0, 0, 0, 1},
                };
    vector<pair<int,int>> ans;
    if(findPath(mat,0,0,ans)){
        for(pair<int,int> p:ans){
            cout<<p.first<<p.second<<"->";
        }
    }
    else{
        cout<<"No path";
    }
}
