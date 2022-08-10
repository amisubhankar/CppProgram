//DFS Backtracking
#include<iostream>
#include<vector>
using namespace std;

bool ratMaze(vector<vector<int>> arr,int n,int r,int c,vector<string> &ans){
    if(r>n-1 || c>n-1 || arr[r][c]==1)  return false;
    else if(r==n-1 && c==n-1){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<"->";
        }
        cout<<r<<c;
        cout<<endl;
        return true;
    }

    string str=to_string(r);
    str+=(c+48);
    ans.push_back(str);
    if(ratMaze(arr,n,r,c+1,ans))    return true;
    if(ratMaze(arr,n,r+1,c,ans))    return true;
    ans.pop_back();
    return false;
}

int main(){
    vector<vector<int>> arr={
                            {0, 1, 0, 1, 1},
                            {0, 0, 0, 0, 0},
                            {1, 0, 1, 0, 1},
                            {0, 0, 1, 0, 0},
                            {1, 0, 0, 1, 0}
                            };

    vector<string> ans;
    ratMaze(arr,arr.size(),0,0,ans);

    return 0;
}

/*
{
   {0, 1, 0, 1, 1},
   {0, 0, 0, 0, 0},
   {1, 0, 1, 0, 1},
   {0, 0, 1, 0, 0},
   {1, 0, 0, 1, 0}
    };

{
        {0,0},
        {0,0}
    };
*/