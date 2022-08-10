//Graph 11)
#include<iostream>
#include<queue>
#define m 3
#define n 3
using namespace std;
class cell{
    public:
    int r,c,time;
    public:
    cell(int r,int c,int time){
        this->r=r;
        this->c=c;
        this->time=time;
    }
};

bool isValid(int r,int c,int mat[m][n]){
    if(r<0||c<0||r>m-1||c>n-1||mat[r][c]==0||mat[r][c]==2){
        return false;
    }
    return true;
}
bool isAllRotten(int mat[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1)    return false;
        }
    }
    return true;
}
int rottenOranges(int mat[m][n]){
    queue<cell> qu;
    //1st enter all the initial rotten oranges
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==2){
                cell obj(i,j,0);
                qu.push(obj);
            }
        }
    }
    int minTime;
    while(!qu.empty()){
        cell obj=qu.front();
        minTime=obj.time;
        qu.pop();
        //check all 4 possibility
        if(isValid(obj.r-1,obj.c,mat)){
            mat[obj.r-1][obj.c]=2;
            cell obj1(obj.r-1,obj.c,obj.time+1);
            qu.push(obj1);
        }
        if(isValid(obj.r,obj.c+1,mat)){
            mat[obj.r][obj.c+1]=2;
            cell obj1(obj.r,obj.c+1,obj.time+1);
            qu.push(obj1);
        }
        if(isValid(obj.r+1,obj.c,mat)){
            mat[obj.r+1][obj.c]=2;
            cell obj1(obj.r+1,obj.c,obj.time+1);
            qu.push(obj1);
        }
        if(isValid(obj.r,obj.c-1,mat)){
            mat[obj.r][obj.c-1]=2;
            cell obj1(obj.r,obj.c-1,obj.time+1);
            qu.push(obj1);
        }
        
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return (isAllRotten(mat))?minTime:-1;
}

int main(){
    int mat[m][n]={
                    {2,1,1},
                    {1,1,0},
                    {0,1,1}
    };
    
    cout<<rottenOranges(mat);
}

/*
{
                    {2,1,0,2,1},
                    {1,0,1,2,1},
                    {0,0,0,2,1}
                  };
*/