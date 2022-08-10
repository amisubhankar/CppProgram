//Graph 14)
#include<iostream>
#include<queue>
#define r 4
#define c 5
using namespace std;
int row[8]={-1,-1,-1,0,1,1,1,0};
int col[8]={-1,0,1,1,1,0,-1,-1};

bool isSafe(bool processed[r][c],int i,int j){
    if(i<0||j<0||i>r-1||j>c-1||processed[i][j]==false){
        return false;
    }
    return true;
}

void BFS(int mat[r][c],bool processed[r][c],queue<pair<int,int>> qu){
    while(!qu.empty()){
        pair<int,int> p=qu.front();
        qu.pop();
        for(int k=0;k<8;k++){
            if(isSafe(processed,row[k]+p.first,col[k]+p.second)){
                processed[row[k]+p.first][col[k]+p.second]=false;
                qu.push({row[k]+p.first,col[k]+p.second});
            }
        }
    }
}

int main(){
    int mat[r][c]=
	{
		{1,1,1,1,0},
		{1,1,0,1,0},
		{1,1,0,0,0},
		{0,0,0,1,1}
	};
    bool processed[r][c]={false};
    //mark all land as True
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]==1)    processed[i][j]=true;
        }
    }
    int iland=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]==1 && processed[i][j]){
                queue<pair<int,int>> qu;
                processed[i][j]=false;
                iland++;
                qu.push({i,j});
                BFS(mat,processed,qu);
            }
        }
    }

    cout<<"No. of ILand = "<<iland;
}

/*
{
    		{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
    		{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
    		{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
    		{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
    		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
    		{ 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
    		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
    		{ 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
    		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
    		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
    	};
r=10,c=10,o/p=5
*/