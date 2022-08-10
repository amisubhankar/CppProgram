#include<iostream>
#include<vector>
using namespace std;

bool findNextPos(vector<vector<int>> &grid,int &row,int &col){
    for(row=0;row<9;row++){
        for(col=0;col<9;col++){
            if(grid[row][col]==0)   return true;
        }
    }
    return false;
}

bool isSafe(vector<vector<int>> &grid,int r,int c,int k){
    //find out corner row index and corner col index
    //that will be our startin val for every box
    int cri=r-(r%3);
    int cci=c-(c%3);

    for(int i=0;i<9;i++){
        if(grid[r][i]==k)   return false;
        if(grid[i][c]==k)   return false;
        if(grid[(i/3)+cri][(i%3)+cci]==k)   return false;
    }
    
    //for box checking seperately
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if(grid[cri+i][cci+j]==k)   return false;
    //     }
    // }

    return true;
}

bool solveSudoku(vector<vector<int>> &grid,int row,int col){
    //all pos is filled so no next Pos is there
    if(!findNextPos(grid,row,col)){
        return true;
    }
    //try to fill a cell by value 1 to 9
    for(int k=1;k<=9;k++){
        //check whether can I put k or not
        if(isSafe(grid,row,col,k)){
            grid[row][col]=k;
            //if placing k is OK for further insertion then solveSudoku()
            //returns true and we should not chng that (row|col)=0
            if(solveSudoku(grid,row,col))
                return true;
            //as solveSudoku() returns false so backtrack to prev soln
            grid[row][col]=0;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> grid= {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if(solveSudoku(grid,0,0)){
        //print
        for(int i=0;i<9;i++){
            if(i==3 || i==6)
                cout<<"-------------------------- "<<endl;
            for(int j=0;j<9;j++){
                if(j==3 || j==6)
                    cout<<" | ";
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"NO SOLUTION";
    }
}