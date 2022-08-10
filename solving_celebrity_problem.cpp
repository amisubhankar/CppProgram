#include<iostream>
using namespace std;

int findCelebrity(int matrix[][4],int row,int col){
    int x=0,y=col-1;

    while(x<y){
        //means x knows y so x can't be a celebrity
        //as celebrity doesn't know anyone
        if(matrix[x][y]==1)
            x++;
        //means x doesn't know y so y can't be a celebrity
        //as everyone knows celebrity
        else
            y--;
    }

    for(int i=0;i<col;i++){
        if(i==x)
            continue;
        //normally if x is celeb then
        //matrix[x][i]=0 as x doesn't know anyone
        //matrix[i][x]=1 as everyone knows x
        if(matrix[x][i]!=0 || matrix[i][x]!=1)
            return -1;
    }
    return x;

}

int main(){
    int matrix[][4]={{0, 0, 1, 0}, 
                     {0, 0, 1, 0}, 
                     {0, 0, 0, 0}, 
                     {0, 0, 1, 0}};
    
    int row=4,col=4;
    int id=findCelebrity(matrix,row,col);

    id==-1?cout<<"Celebrity not found":cout<<"Celebrity is : "<<id;

    return 0;
}